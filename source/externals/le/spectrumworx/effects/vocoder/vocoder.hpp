////////////////////////////////////////////////////////////////////////////////
///
/// \file vocoder.hpp
/// -----------------
///
/// Copyright (c) 2009 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef vocoder_hpp__08C0E1D2_AA0E_4399_9684_AEB65477A0F3
#define vocoder_hpp__08C0E1D2_AA0E_4399_9684_AEB65477A0F3
#if defined( _MSC_VER ) && !defined( DOXYGEN_ONLY )
#pragma once
#endif // MSVC && !Doxygen
//------------------------------------------------------------------------------
#include "le/spectrumworx/effects/parameters.hpp"
#include "le/parameters/enumerated/parameter.hpp"
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

////////////////////////////////////////////////////////////////////////////////
///
/// \class Vocoder
///
/// \ingroup Effects
///
/// \brief Classic vocoder.
///
/// A classic vocoding effect where the frequency spectrum of the modulator is
/// used to modulate the carrier. This is achieved via cross-synthesis.
/// Cross-synthesis is a technique of impressing the spectral envelope of one
/// sound on the (flattened) spectrum of another. The modulator may be a voice,
/// and the carrier may be any spectrally rich sound.
///
////////////////////////////////////////////////////////////////////////////////

struct Vocoder
{
    enum FilterMethodValue { CepstrumUdoBrick, CepstrumBrick, CepstrumHamming, MovingAverage, Envelope, MelEnvelope, Passthrough };
    class FilterMethod : public LE::Parameters::EnumeratedParameter<7> {};
    class EnvelopeBorder : public LinearUnsignedInteger::Modify<Traits::Minimum<0>, Traits::Maximum<12000>, Traits::Default<1000>, Traits::Unit<' Hz'>> {};
    class NoiseIntensity : public LinearUnsignedInteger::Modify<Traits::Minimum<0>, Traits::Maximum<100>, Traits::Default<0>, Traits::Unit<'%'>> {};

    LE_DEFINE_PARAMETERS(
        EnvelopeBorder,
        NoiseIntensity,
        FilterMethod
    );

    /// \typedef EnvelopeBorder
    /// \brief Controls the perceived "smoothness" of the modulator.
    /// \typedef NoiseIntensity
    /// \brief
    /// \typedef FilterMethod
    /// \brief


    static bool const usesSideChannel = true;

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

#endif // vocoder_hpp
