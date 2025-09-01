////////////////////////////////////////////////////////////////////////////////
///
/// \file lorisAnalysisEngine.hpp
/// ------------------------------
///
/// Loris spectral analysis engine wrapper for SpectrumWorx integration.
///
/// Copyright (c) 2024. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef lorisAnalysisEngine_hpp__A1B2C3D4_E5F6_7890_ABCD_123456789ABC
#define lorisAnalysisEngine_hpp__A1B2C3D4_E5F6_7890_ABCD_123456789ABC
#pragma once
//------------------------------------------------------------------------------
#ifdef LE_SW_LORIS_ENGINE

#include "channelData_fwd.hpp"
#include "le/utility/buffers.hpp"

#include <loris.h>
#include <vector>
#include <memory>
#include <cstdint>

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
///
/// \class LorisAnalysisEngine
///
/// \brief Wrapper class that integrates Loris spectral analysis with 
/// SpectrumWorx's audio processing pipeline.
///
/// This class provides a bridge between SpectrumWorx's FFT-based processing
/// and Loris's sinusoidal modeling approach, allowing for more sophisticated
/// spectral analysis and manipulation.
///
////////////////////////////////////////////////////////////////////////////////

class LorisAnalysisEngine
{
public:
    ////////////////////////////////////////////////////////////////////////////////
    /// \struct Parameters
    /// 
    /// Configuration parameters for Loris analysis, mapped to SpectrumWorx's
    /// parameter system.
    ////////////////////////////////////////////////////////////////////////////////
    struct Parameters
    {
        float fundamentalFreq_Hz;      ///< Expected fundamental frequency (default: 440 Hz)
        float frequencyDrift_Hz;       ///< Maximum frequency drift for partial tracking (default: 50 Hz)
        float amplitudeFloor;          ///< Minimum amplitude threshold (default: -60 dB)
        float hopTime_sec;             ///< Analysis hop time in seconds
        float windowWidth_sec;         ///< Analysis window width in seconds
        float sidelobeLevel_dB;        ///< Kaiser window sidelobe level (default: -90 dB)
        
        /// Default constructor with sensible defaults
        Parameters();
        
        /// Constructor that derives parameters from FFT settings
        Parameters(std::uint16_t fftSize, float sampleRate);
    };

public:
    LorisAnalysisEngine();
    ~LorisAnalysisEngine();

    /// Initialize the engine with the given parameters
    void initialize(const Parameters& params, float sampleRate);
    
    /// Reset the engine state (clear partial history)
    void reset();
    
    /// Analyze time-domain audio data and produce Loris PartialList
    /// Returns true if analysis was successful
    bool analyzeFrame(
        const float* timeData, 
        std::uint16_t frameSize,
        double timeStamp_sec
    );
    
    /// Convert current Loris partials to SpectrumWorx amplitude/phase format
    void convertToAmPh(
        FullChannelData_AmPh& amPhData,
        std::uint16_t fftSize,
        float sampleRate
    ) const;
    
    /// Convert current Loris partials to SpectrumWorx real/imaginary format  
    void convertToReIm(
        FullChannelData_ReIm& reImData,
        std::uint16_t fftSize,
        float sampleRate
    ) const;
    
    /// Convert amplitude/phase data back to Loris PartialList
    /// This allows effects to modify spectral data and pass it back to Loris
    void convertFromAmPh(
        const FullChannelData_AmPh& amPhData,
        std::uint16_t fftSize,
        float sampleRate,
        double timeStamp_sec
    );
    
    /// Synthesize Loris partials to time-domain data
    void synthesizeFrame(
        float* timeData,
        std::uint16_t frameSize,
        double timeStamp_sec,
        float sampleRate
    ) const;
    
    /// Get the current number of active partials
    std::size_t getPartialCount() const;
    
    /// Export current partials to SDIF file (for analysis/debugging)
    bool exportToSDIF(const char* filename) const;
    
    /// Import partials from SDIF file
    /// \param filename Path to input SDIF file
    /// \param timeStamp_sec Time stamp to associate with imported data
    /// \return true if import succeeded, false otherwise
    bool importFromSDIF(const char* filename, double timeStamp_sec = 0.0);

    /// Access current parameters (read-only)
    const Parameters& getParameters() const { return params_; }
    
    /// Check if the engine is properly initialized
    bool isInitialized() const { return initialized_; }

private:
    // Internal helper methods
    void setupAnalyzer();
    void cleanupResources();
    
    static float binToFrequency(std::uint16_t bin, std::uint16_t fftSize, float sampleRate);
    static std::uint16_t frequencyToBin(float freq, std::uint16_t fftSize, float sampleRate);
    
    // Convert between SpectrumWorx and Loris amplitude representations
    static float amplitudeToLoris(float swAmplitude);
    static float amplitudeFromLoris(float lorisAmplitude);

private:
    Parameters params_;
    bool initialized_;
    float sampleRate_;
    
    // Current partial list from analysis
    PartialList* currentPartials_;
    
    // Analyzer configuration flag
    bool analyzerConfigured_;
    
    // Temporary buffers for conversion
    mutable std::vector<float> tempAmplitudes_;
    mutable std::vector<float> tempPhases_;
    mutable std::vector<float> tempReals_;
    mutable std::vector<float> tempImags_;
    
    // Frame tracking
    double currentTime_;
    std::uint32_t frameCounter_;
    
}; // class LorisAnalysisEngine

//------------------------------------------------------------------------------
LE_IMPL_NAMESPACE_END( Engine )
//------------------------------------------------------------------------------
} // namespace SW
//------------------------------------------------------------------------------
} // namespace LE
//------------------------------------------------------------------------------

#endif // LE_SW_LORIS_ENGINE
#endif // lorisAnalysisEngine_hpp
