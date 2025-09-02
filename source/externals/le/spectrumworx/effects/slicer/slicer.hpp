////////////////////////////////////////////////////////////////////////////////
///
/// \file slicer.hpp
/// ----------------
///
/// Copyright (c) 2009 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef slicer_hpp__5484C80F_BF0B_46A9_BCB8_8F68F22B46DA
#define slicer_hpp__5484C80F_BF0B_46A9_BCB8_8F68F22B46DA
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
/// \class Slicer
///
/// \ingroup Effects
///
/// \brief Slice the signal into two parts.
///
/// This effect slices the signal into chunks that are alternated with one of 
/// three different options.
/// 
////////////////////////////////////////////////////////////////////////////////

struct Slicer
{
    enum ModeValue { Hold, Silence, Side };
    class Mode : public LE::Parameters::EnumeratedParameter<3> {};
    class TimeOn : public LinearUnsignedInteger::Modify<Traits::Minimum<10>, Traits::Maximum<1000>, Traits::Default<250>, Traits::Unit<' ms'>> {};
    class TimeOff : public LinearUnsignedInteger::Modify<Traits::Minimum<10>, Traits::Maximum<1000>, Traits::Default<100>, Traits::Unit<' ms'>> {};

    LE_DEFINE_PARAMETERS(
        TimeOn,
        TimeOff,
        Mode
    );

    /// \typedef TimeOn
    /// \brief Determines the length of the main input slices, this slice goes
    /// through unmodified.
    /// \typedef TimeOff
    /// \brief Determines the length of the modified slices.
    /// \typedef Mode
    /// \brief Determines what modified slices contain.
    ///   - Hold: fills the gaps with a "frozen" sample of the last frame from
    /// the main input before the slice began.
    ///   - Silence: fills the slice with silence.
    ///   - Side: fills the slice with Side channel.

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

#endif // slicer_hpp
