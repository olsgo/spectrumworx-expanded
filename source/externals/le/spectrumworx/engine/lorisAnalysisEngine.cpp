////////////////////////////////////////////////////////////////////////////////
///
/// lorisAnalysisEngine.cpp
/// ------------------------
///
/// Loris spectral analysis engine wrapper implementation.
///
/// Copyright (c) 2024. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#include "lorisAnalysisEngine.hpp"

#ifdef LE_SW_LORIS_ENGINE

#include "channelDataAmPh.hpp" 
#include "channelDataReIm.hpp"
#include "le/math/conversion.hpp"
#include "le/math/constants.hpp"
#include "le/utility/platformSpecifics.hpp"

#include "boost/assert.hpp"

#include <loris.h>
#include <algorithm>
#include <cmath>
#include <cstring>

//------------------------------------------------------------------------------
namespace LE
{
//------------------------------------------------------------------------------
namespace SW
{
//------------------------------------------------------------------------------
LE_IMPL_NAMESPACE_BEGIN( Engine )
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// LorisAnalysisEngine::Parameters implementation
////////////////////////////////////////////////////////////////////////////////

LorisAnalysisEngine::Parameters::Parameters()
    :
    fundamentalFreq_Hz(440.0f),
    frequencyDrift_Hz(50.0f),
    amplitudeFloor(-60.0f),       // -60 dB
    hopTime_sec(0.01f),           // 10ms hop
    windowWidth_sec(0.02f),       // 20ms window
    sidelobeLevel_dB(-90.0f)      // -90 dB Kaiser window
{
}

LorisAnalysisEngine::Parameters::Parameters(std::uint16_t fftSize, float sampleRate)
    :
    fundamentalFreq_Hz(440.0f),
    frequencyDrift_Hz(sampleRate / (fftSize * 8.0f)), // Adapt to frequency resolution
    amplitudeFloor(-60.0f),
    hopTime_sec(fftSize / (sampleRate * 4.0f)),       // 4x overlap like SpectrumWorx
    windowWidth_sec(fftSize / sampleRate),            // Match FFT window
    sidelobeLevel_dB(-90.0f)
{
}

////////////////////////////////////////////////////////////////////////////////
// LorisAnalysisEngine implementation
////////////////////////////////////////////////////////////////////////////////

LorisAnalysisEngine::LorisAnalysisEngine()
    :
    initialized_(false),
    sampleRate_(44100.0f),
    currentPartials_(nullptr),
    analyzerConfigured_(false),
    currentTime_(0.0),
    frameCounter_(0)
{}

LorisAnalysisEngine::~LorisAnalysisEngine()
{
    cleanupResources();
}

void LorisAnalysisEngine::initialize(const Parameters& params, float sampleRate)
{
    BOOST_ASSERT(sampleRate > 0);
    
    // Clean up any existing resources
    cleanupResources();
    
    params_ = params;
    sampleRate_ = sampleRate;
    currentTime_ = 0.0;
    frameCounter_ = 0;
    
    // Configure Loris analyzer singleton
    try 
    {
        configureAnalyzer();
        
        // Create empty partial list
        currentPartials_ = createPartialList();
        if (!currentPartials_)
        {
            cleanupResources();
            return;
        }
        
        initialized_ = true;
        analyzerConfigured_ = true;
    }
    catch (...)
    {
        cleanupResources();
        throw;
    }
}

void LorisAnalysisEngine::reset()
{
    if (!initialized_) return;
    
    currentTime_ = 0.0;
    frameCounter_ = 0;
    
    // Clear the partial list
    if (currentPartials_)
    {
        destroyPartialList(currentPartials_);
        currentPartials_ = createPartialList();
    }
}

bool LorisAnalysisEngine::analyzeFrame(
    const float* timeData, 
    std::uint16_t frameSize,
    double timeStamp_sec)
{
    if (!initialized_ || !analyzerConfigured_ || !currentPartials_)
        return false;
        
    BOOST_ASSERT(timeData != nullptr);
    BOOST_ASSERT(frameSize > 0);
    
    try
    {
        // Update current time
        currentTime_ = timeStamp_sec;
        
        // Analyze the frame using Loris
        // Note: Loris expects double-precision samples, so we need to convert
        std::vector<double> doubleData(frameSize);
        for (std::uint16_t i = 0; i < frameSize; ++i)
        {
            doubleData[i] = static_cast<double>(timeData[i]);
        }
        
        // Perform analysis using Loris singleton analyzer - this modifies currentPartials_ list
        analyze(doubleData.data(), frameSize, sampleRate_, currentPartials_);
        
        ++frameCounter_;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

void LorisAnalysisEngine::convertToAmPh(
    FullChannelData_AmPh& amPhData,
    std::uint16_t fftSize,
    float sampleRate) const
{
    if (!initialized_ || !currentPartials_)
        return;
        
    const std::uint16_t numBins = fftSize / 2 + 1;
    
    // Clear output buffers
    std::fill(amPhData.amps().begin(), amPhData.amps().end(), 0.0f);
    std::fill(amPhData.phases().begin(), amPhData.phases().end(), 0.0f);
    
    // Get the number of partials
    const std::size_t numPartials = partialListSize(currentPartials_);
    
    // Convert each Loris partial to amplitude/phase representation
    for (std::size_t p = 0; p < numPartials; ++p)
    {
        Partial* partial = partialListAt(currentPartials_, p);
        if (!partial) continue;
        
        // Get the partial's current state at the current time
        const double frequency = partialFrequencyAt(partial, currentTime_);
        const double amplitude = partialAmplitudeAt(partial, currentTime_);
        const double phase = partialPhaseAt(partial, currentTime_);
        
        if (amplitude <= 0.0) continue;
        
        // Convert frequency to FFT bin
        const std::uint16_t bin = frequencyToBin(static_cast<float>(frequency), fftSize, sampleRate);
        if (bin >= numBins) continue;
        
        // Convert amplitude and add to the appropriate bin
        const float swAmplitude = amplitudeFromLoris(static_cast<float>(amplitude));
        const float swPhase = static_cast<float>(phase);
        
        // Accumulate in case multiple partials map to the same bin
        amPhData.amps()[bin] += swAmplitude;
        
        // Use the phase of the strongest partial in each bin
        if (swAmplitude > amPhData.amps()[bin] - swAmplitude)
        {
            amPhData.phases()[bin] = swPhase;
        }
    }
}

void LorisAnalysisEngine::convertToReIm(
    FullChannelData_ReIm& reImData,
    std::uint16_t fftSize,
    float sampleRate) const
{
    if (!initialized_ || !currentPartials_)
        return;
        
    const std::uint16_t numBins = fftSize / 2 + 1;
    
    // Clear output buffers
    std::fill(reImData.reals().begin(), reImData.reals().end(), 0.0f);
    std::fill(reImData.imags().begin(), reImData.imags().end(), 0.0f);
    
    // Get the number of partials
    const std::size_t numPartials = partialListSize(currentPartials_);
    
    // Convert each Loris partial to real/imaginary representation  
    for (std::size_t p = 0; p < numPartials; ++p)
    {
        Partial* partial = partialListAt(currentPartials_, p);
        if (!partial) continue;
        
        // Get the partial's current state at the current time
        const double frequency = partialFrequencyAt(partial, currentTime_);
        const double amplitude = partialAmplitudeAt(partial, currentTime_);
        const double phase = partialPhaseAt(partial, currentTime_);
        
        if (amplitude <= 0.0) continue;
        
        // Convert frequency to FFT bin
        const std::uint16_t bin = frequencyToBin(static_cast<float>(frequency), fftSize, sampleRate);
        if (bin >= numBins) continue;
        
        // Convert to real/imaginary using polar to rectangular conversion
        const float swAmplitude = amplitudeFromLoris(static_cast<float>(amplitude));
        const float swPhase = static_cast<float>(phase);
        
        reImData.reals()[bin] += swAmplitude * std::cos(swPhase);
        reImData.imags()[bin] += swAmplitude * std::sin(swPhase);
    }
}

void LorisAnalysisEngine::convertFromAmPh(
    const FullChannelData_AmPh& amPhData,
    std::uint16_t fftSize,
    float sampleRate,
    double timeStamp_sec)
{
    if (!initialized_ || !currentPartials_)
        return;
    
    // Clear current partials - we're replacing them with new data from SpectrumWorx
    destroyPartialList(currentPartials_);
    currentPartials_ = createPartialList();
    
    currentTime_ = timeStamp_sec;
    
    // Convert each FFT bin with significant energy into a Loris partial
    const std::uint16_t numBins = fftSize / 2 + 1;
    const float minAmplitude = amplitudeToLoris(std::pow(10.0f, params_.amplitudeFloor / 20.0f));
    
    for (std::uint16_t bin = 1; bin < numBins - 1; ++bin) // Skip DC and Nyquist
    {
        const float amplitude = amPhData.amps()[bin];
        const float phase = amPhData.phases()[bin];
        
        if (amplitude < minAmplitude) continue;
        
        // Convert bin to frequency
        const float frequency = binToFrequency(bin, fftSize, sampleRate);
        
        // Create a new Loris partial
        Partial* partial = createPartial();
        if (partial)
        {
            // Add a breakpoint at the current time
            const double lorisAmplitude = amplitudeToLoris(amplitude);
            addBreakpoint(partial, timeStamp_sec, frequency, lorisAmplitude, static_cast<double>(phase));
            
            // Add the partial to the list
            partialListAppend(currentPartials_, partial);
        }
    }
}

void LorisAnalysisEngine::synthesizeFrame(
    float* timeData,
    std::uint16_t frameSize,
    double timeStamp_sec,
    float sampleRate) const
{
    if (!initialized_ || !currentPartials_ || !timeData)
        return;
        
    BOOST_ASSERT(frameSize > 0);
    
    // Clear output buffer
    std::fill(timeData, timeData + frameSize, 0.0f);
    
    try
    {
        // Use Loris synthesis to generate time-domain samples
        std::vector<double> doubleOutput(frameSize, 0.0);
        
        // Synthesize the partial list at the given time
        synthesize(currentPartials_, doubleOutput.data(), frameSize, sampleRate);
        
        // Convert back to float
        for (std::uint16_t i = 0; i < frameSize; ++i)
        {
            timeData[i] = static_cast<float>(doubleOutput[i]);
        }
    }
    catch (...)
    {
        // If synthesis fails, output silence
        std::fill(timeData, timeData + frameSize, 0.0f);
    }
}

std::size_t LorisAnalysisEngine::getPartialCount() const
{
    if (!initialized_ || !currentPartials_)
        return 0;
        
    return partialListSize(currentPartials_);
}

bool LorisAnalysisEngine::exportToSDIF(const char* filename) const
{
    if (!initialized_ || !currentPartials_ || !filename)
        return false;
        
    try
    {
        exportSDIF(currentPartials_, filename);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool LorisAnalysisEngine::importFromSDIF(const char* filename, double timeStamp_sec)
{
    if (!initialized_ || !filename)
        return false;
        
    try
    {
        // Clean up existing partials
        if (currentPartials_)
        {
            destroyPartialList(currentPartials_);
            currentPartials_ = nullptr;
        }
        
        // Import partials from SDIF file
        currentPartials_ = importSDIF(filename);
        if (!currentPartials_)
            return false;
            
        // Update current time to the provided timestamp
        currentTime_ = timeStamp_sec;
        frameCounter_ = 0; // Reset frame counter for imported data
        
        return true;
    }
    catch (...)
    {
        // If import fails, ensure we have a valid empty partial list
        if (currentPartials_)
        {
            destroyPartialList(currentPartials_);
        }
        currentPartials_ = createPartialList();
        return false;
    }
}

void LorisAnalysisEngine::configureAnalyzer()
{
    // Configure the Loris singleton analyzer with our parameters
    // Using the procedural API from loris.h
    configure(
        params_.fundamentalFreq_Hz,
        params_.amplitudeFloor,
        params_.windowWidth_sec,
        params_.hopTime_sec,
        params_.sidelobeLevel_dB
    );
    
    // Configure frequency drift tolerance
    setFreqDrift(params_.frequencyDrift_Hz);
    
    analyzerConfigured_ = true;
}

void LorisAnalysisEngine::cleanupResources()
{
    if (currentPartials_)
    {
        destroyPartialList(currentPartials_);
        currentPartials_ = nullptr;
    }
    
    initialized_ = false;
    analyzerConfigured_ = false;
}

float LorisAnalysisEngine::binToFrequency(std::uint16_t bin, std::uint16_t fftSize, float sampleRate)
{
    return (static_cast<float>(bin) * sampleRate) / static_cast<float>(fftSize);
}

std::uint16_t LorisAnalysisEngine::frequencyToBin(float freq, std::uint16_t fftSize, float sampleRate)
{
    const float binFloat = (freq * static_cast<float>(fftSize)) / sampleRate;
    return static_cast<std::uint16_t>(std::round(binFloat));
}

float LorisAnalysisEngine::amplitudeToLoris(float swAmplitude)
{
    // SpectrumWorx typically uses linear amplitude, Loris expects linear as well
    return swAmplitude;
}

float LorisAnalysisEngine::amplitudeFromLoris(float lorisAmplitude)
{
    // Both use linear amplitude representation
    return lorisAmplitude;
}

//------------------------------------------------------------------------------
LE_IMPL_NAMESPACE_END( Engine )
//------------------------------------------------------------------------------
} // namespace SW
//------------------------------------------------------------------------------  
} // namespace LE
//------------------------------------------------------------------------------

#endif // LE_SW_LORIS_ENGINE
