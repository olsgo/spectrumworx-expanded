////////////////////////////////////////////////////////////////////////////////
///
/// \file exImploder.hpp
/// --------------------
///
/// Copyright (c) 2009 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef exImploder_hpp__AD0B75AE_AEAC_4D7E_A02F_DB3E79D409AC
#define exImploder_hpp__AD0B75AE_AEAC_4D7E_A02F_DB3E79D409AC
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
    struct ExImPloder ///<
    {
        class MagnitudeScale : public LinearUnsignedInteger::Modify<Traits::Minimum<1>, Traits::Maximum<200>, Traits::Default<50>, Traits::Unit<' s'>> {};
        class Gliss : public LinearSignedInteger::Modify<Traits::Minimum<-300>, Traits::Maximum<300>, Traits::Default<-100>, Traits::Unit<' "/s'>> {};
        class Threshold : public LinearSignedInteger::Modify<Traits::Minimum<-120>, Traits::Maximum<0>, Traits::Default<-120>, Traits::Unit<' dB'>> {};
        class Gate : public Threshold {};

        /// \typedef MagnitudeScale
        /// Used by all ExImploder effects which is only conveniently
        /// renamed to a more intuitive name for Exploder and Imploder effects
        /// (Growth and Decay respectively).

        static bool const usesSideChannel = false;
    };
} // namespace Detail
/// \brief parameters shared by all ExImploder effects


////////////////////////////////////////////////////////////////////////////////
///
/// \class PVImploder
///
/// \ingroup Effects
///
/// \brief Spectral implosion with glissando.  
///
/// Imploder freezes incoming high amplitudes and introduces a slow decay 
/// towards the selected level. Additionally, the frequency is gradually pitch 
/// shifted (controlled by the Glissando). Amplitudes are decayed until a higher 
/// signal is received at the input or until the Limit is reached.
/// 
////////////////////////////////////////////////////////////////////////////////

struct PVImploder : Detail::ExImPloder
{
    /// \name Parameters
    /// @{
    typedef Detail::ExImPloder::Gate      Gate     ;
    typedef Detail::ExImPloder::Gliss     Gliss    ;
    typedef Detail::ExImPloder::Threshold Threshold;
    /// @}

    class Decay : public Detail::ExImPloder::MagnitudeScale {};

    LE_DEFINE_PARAMETERS(
        Decay,
        Gliss,
        Threshold,
        Gate
    );

    /// \typedef Decay
    /// \brief Time needed to decay from 0 to -120 dB.
    /// \typedef Gliss
    /// \brief Pitch-shift the decaying sound.
    /// \typedef Threshold
    /// \brief Amplitudes are decayed until a higher signal is received at the
    ///        input or until Threshold is reached.

    static char const title      [];
    static char const description[];
};


////////////////////////////////////////////////////////////////////////////////
///
/// \class Imploder
///
/// \ingroup Effects
///
/// \brief Spectral implosion with glissando.  
///
/// Imploder freezes incoming high amplitudes and introduces a slow decay 
/// towards the selected level. Additionally, the frequency is gradually pitch 
/// shifted (controlled by the Glissando). Amplitudes are decayed until a higher 
/// signal is received at the input or until the Limit is reached.
///
////////////////////////////////////////////////////////////////////////////////

struct Imploder : PVImploder
{
    static char const title[];
};


////////////////////////////////////////////////////////////////////////////////
///
/// \class PVExploder
///
/// \ingroup Effects
///
/// \brief Spectral accumulator with glissando.  
///
/// Exploder freezes high amplitudes and ramps them up. Glissando is applied 
/// in the same way as it is in the Imploder. Amplitudes are ramped up until a 
/// louder signal is received at the input or until the Limit is reached.
///
////////////////////////////////////////////////////////////////////////////////

struct PVExploder : Detail::ExImPloder
{
    /// \name Parameters
    /// @{
    typedef Detail::ExImPloder::Gate Gate;
    /// @}

    class Growth : public Detail::ExImPloder::MagnitudeScale {};
    class Gliss : public Detail::ExImPloder::Gliss::Modify<Traits::Default<100>> {};
    class Threshold : public Detail::ExImPloder::Threshold::Modify<Traits::Default<-40>> {};

    LE_DEFINE_PARAMETERS(
        Growth,
        Gliss,
        Threshold,
        Gate
    );

    /// \typedef Growth
    /// \brief Time needed to grow from 0 to 120 dB.
    /// \typedef Gliss
    /// \brief Pitch-shift the growing sound.
    /// \typedef Threshold
    /// \brief Amplitudes are ramped up until a higher signal is received or
    ///        until Threshold is reached.

    static char const title      [];
    static char const description[];
};


////////////////////////////////////////////////////////////////////////////////
///
/// \class Exploder
///
/// \ingroup Effects
///
/// \brief Spectral accumulator with glissando.  
///
/// Exploder freezes high amplitudes and ramps them up. Glissando is applied 
/// in the same way as it is in the Imploder. Amplitudes are ramped up until a 
/// louder signal is received at the input or until the Limit is reached.
///
////////////////////////////////////////////////////////////////////////////////

struct Exploder : PVExploder
{
    static char const title[];
};

//------------------------------------------------------------------------------
} // namespace Effects
//------------------------------------------------------------------------------
} // namespace SW
//------------------------------------------------------------------------------
} // namespace LE
//------------------------------------------------------------------------------

#include "boost/config/abi_suffix.hpp"

#endif // exImploder_hpp
