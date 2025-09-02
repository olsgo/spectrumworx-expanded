////////////////////////////////////////////////////////////////////////////////
///
/// \file freqverb.hpp
/// ------------------
///
/// Copyright (c) 2009 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef freqverb_hpp__338562C9_17C6_4009_876E_4756164099DC
#define freqverb_hpp__338562C9_17C6_4009_876E_4756164099DC
#if defined( _MSC_VER ) && !defined( DOXYGEN_ONLY )
#pragma once
#endif // MSVC && !Doxygen
//------------------------------------------------------------------------------
#include "le/spectrumworx/effects/parameters.hpp"
#include "le/parameters/linear/parameter.hpp"
#include "le/parameters/symmetric/parameter.hpp"

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

////////////////////////////////////////////////////////////////////////////////
///
/// \class Freqverb
///
/// \ingroup Effects
///
/// \brief Creates a reverberant sound. 
///
/// Frequency domain reverb with ability to pitch-shift every single 
/// reverberation. There are many echoes in a short time period that human ears 
/// can't differentiate between them. The Time60dB parameter governs how long 
/// the sound reverberates. The longer the setting, the more sound builds up. 
/// The Room size parameter controls how much attenuation is applied to each 
/// reflection. Pitch function pitch shifts each reverberation. The Mix 
/// parameter controls the ratio of affected and unaffected signal. 
/// 
////////////////////////////////////////////////////////////////////////////////

struct Freqverb
{
    class Time60dB : public LinearFloat::Modify<Traits::Minimum<100>, Traits::Maximum<20000>, Traits::Default<2500>, Traits::ValuesDenominator<1000>, Traits::Unit<' s'>> {};
    class RoomSize : public LinearFloat::Modify<Traits::Minimum<-24>, Traits::Maximum<0>, Traits::Default<-3>, Traits::Unit<' dB'>> {};
    class ReverbPitch : public SymmetricFloat::Modify<Traits::MaximumOffset<48>, Traits::Unit<' 
/s'>> {};
    class HFAbsorption : public LinearUnsignedInteger::Modify<Traits::Minimum<0>, Traits::Maximum<100>, Traits::Default<5>, Traits::Unit<' %'> > {};

    LE_DEFINE_PARAMETERS(
        Time60dB,
        RoomSize,
        ReverbPitch,
        HFAbsorption
    );

    /// \typedef Time60dB
    /// \brief Specifies the life time of reverberation (time needed for
    /// incoming sound to lose 60 dB.
    /// \typedef RoomSize
    /// \brief Controls how much attenuation is applied to each reflection.
    /// \typedef ReverbPitch
    /// \brief Specifies how much is the reverberated sound pitch-shifted per
    /// second of reflection.
	/// \typedef HFAbsorbtion
	/// \brief Increase to absorb high-frequencies faster than low frequencies. 


    static bool const usesSideChannel = false;

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

#endif // freqverb_hpp
