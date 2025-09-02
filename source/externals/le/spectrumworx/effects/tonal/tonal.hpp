////////////////////////////////////////////////////////////////////////////////
///
/// \file tonal.hpp
/// ---------------
///
/// Copyright (c) 2009 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef tonal_hpp__71A9A670_AA87_4755_A67A_A61833B57203
#define tonal_hpp__71A9A670_AA87_4755_A67A_A61833B57203
#if defined( _MSC_VER ) && !defined( DOXYGEN_ONLY )
#pragma once
#endif // MSVC && !Doxygen
//------------------------------------------------------------------------------
#include "le/spectrumworx/effects/parameters.hpp"
#include "le/parameters/linear/parameter.hpp"

#include "boost/config/abi_prefix.hpp"
//------------------------------------------------------------------------------
namespace LE
{
//------------------------------------------------------------------------------
namespace SW
{
//------------------------------------------------------------------------------
namespace Effects
{
//------------------------------------------------------------------------------

namespace Detail
{
    struct TonalBase ///<
    {
        class Strength : public LinearFloat::Modify<Traits::Minimum<0>, Traits::Maximum<90>, Traits::Default<15>, Traits::Unit<' dB'>> {};
        class GlobalThreshold : public LinearFloat::Modify<Traits::Minimum<10>, Traits::Maximum<120>, Traits::Default<30>, Traits::Unit<' dB'>> {};
        class LocalThreshold : public LinearFloat::Modify<Traits::Minimum<0>, Traits::Maximum<120>, Traits::Default<10>, Traits::Unit<' dB'>> {};
        class Attenuation : public LinearFloat::Modify<Traits::Minimum<0>, Traits::Maximum<60>, Traits::Default<20>, Traits::Unit<' dB'>> {};

        /// \typedef Strength
        /// \brief How strong the peak must be to be considered tonal.
        /// \typedef GlobalThreshold
        /// \brief Global (across frames) threshold under which peaks are not
        /// detected.
        /// \typedef LocalThreshold
        /// \brief Local threshold (current frame only) under which peaks are not
        /// detected.
        /// \typedef Attenuation
        /// \brief Intensity of attenuation to apply to non-tonal parts.

        static bool const usesSideChannel = false;
    };
} // namespace Detail

////////////////////////////////////////////////////////////////////////////////
///
/// \class Tonal
///
/// \ingroup Effects
///
/// \brief Suppresses non-tonal parts of the signal. 
/// 
/// Lets through only highly-tonal frequencies. Finds peaks in the spectrum, 
/// then it estimates the peak strength (how strong the peak is when compared 
/// to its neighbours), and if the strength is above the value determined by 
/// the strength parameter, and if the peak is stronger than that determined 
/// by the global threshold or local threshold, the peak will be passed through. 
/// The rest of the signal is attenuated.
///
////////////////////////////////////////////////////////////////////////////////

struct Tonal : Detail::TonalBase
{
    LE_DEFINE_PARAMETERS(
        Strength,
        GlobalThreshold,
        LocalThreshold,
        Attenuation
    );

    static char const title      [];
    static char const description[];
};


////////////////////////////////////////////////////////////////////////////////
///
/// \class Atonal
///
/// \ingroup Effects
///
/// \brief Suppresses tonal parts of the signal. 
/// 
/// Attenuates peaks and allows the non-peak components to pass through.
/// 
////////////////////////////////////////////////////////////////////////////////

struct Atonal : Detail::TonalBase
{
    /// \name Parameters
    /// @{
    typedef Detail::TonalBase::LocalThreshold LocalThreshold;
    /// @}

    class Strength : public Detail::TonalBase::Strength::Modify<Traits::Default<0>, Traits::ValuesDenominator<1>> {};
    class GlobalThreshold : public Detail::TonalBase::GlobalThreshold::Modify<Traits::Default<60>, Traits::ValuesDenominator<1>> {};
    class Attenuation : public Detail::TonalBase::Attenuation::Modify<Traits::Default<30>, Traits::ValuesDenominator<1>> {};

    LE_DEFINE_PARAMETERS(
        Strength,
        GlobalThreshold,
        LocalThreshold,
        Attenuation
    );

    /// \typedef Strength
    /// \brief How strong the peak must be to be considered tonal.
    /// \typedef GlobalThreshold
    /// \brief Global (across frames) threshold under which peaks are not
    /// detected.
    /// \typedef LocalThreshold
    /// \brief Local threshold (current frame only) under which peaks are not
    /// detected.
    /// \typedef Attenuation
    /// \brief Intensity of attenuation to apply to non-tonal parts.

    static char const title      [];
    static char const description[];
};

//------------------------------------------------------------------------------
} // namespace Effects
//------------------------------------------------------------------------------
} // namespace SW
//------------------------------------------------------------------------------
} // namespace LE
//------------------------------------------------------------------------------

#include "boost/config/abi_suffix.hpp"

#endif // tonal_hpp
