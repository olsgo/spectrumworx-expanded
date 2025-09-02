////////////////////////////////////////////////////////////////////////////////
///
/// \file tuneWorx.hpp
/// ------------------
///
/// Copyright (c) 2009 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef tuneWorx_hpp__08D752F7_70CC_436C_8C8A_BE59A2A4900D
#define tuneWorx_hpp__08D752F7_70CC_436C_8C8A_BE59A2A4900D
#if defined( _MSC_VER ) && !defined( DOXYGEN_ONLY )
#pragma once
#endif // MSVC && !Doxygen
//------------------------------------------------------------------------------
#include "le/spectrumworx/effects/commonParameters.hpp"
#include "le/spectrumworx/effects/parameters.hpp"
#include "le/parameters/boolean/parameter.hpp"
#include "le/parameters/enumerated/parameter.hpp"
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

namespace Detail
{
    struct TuneWorxBase ///<
    {
        /// \name Parameters
        /// @{
        typedef CommonParameters::SpringType SpringType;
        /// @}

        enum KeyValue { A, Ais, B, C, Cis, D, Dis, E, F, Fis, G, Gis };
        class Key : public LE::Parameters::EnumeratedParameter<12> {};

    #ifndef LE_SIMPLE_TUNEWORX
        class Semi01 : public Boolean {};
        class Semi02 : public Boolean {};
        class Semi03 : public Boolean {};
        class Semi04 : public Boolean {};
        class Semi05 : public Boolean {};
        class Semi06 : public Boolean {};
        class Semi07 : public Boolean {};
        class Semi08 : public Boolean {};
        class Semi09 : public Boolean {};
        class Semi10 : public Boolean {};
        class Semi11 : public Boolean {};
        class Semi12 : public Boolean {};
        class BypassSemi01 : public Boolean {};
        class BypassSemi02 : public Boolean {};
        class BypassSemi03 : public Boolean {};
        class BypassSemi04 : public Boolean {};
        class BypassSemi05 : public Boolean {};
        class BypassSemi06 : public Boolean {};
        class BypassSemi07 : public Boolean {};
        class BypassSemi08 : public Boolean {};
        class BypassSemi09 : public Boolean {};
        class BypassSemi10 : public Boolean {};
        class BypassSemi11 : public Boolean {};
        class BypassSemi12 : public Boolean {};
        class Vibrato : public Boolean {};
        class PitchMinFreq : public LinearFloat::Modify<Traits::Minimum<50>, Traits::Maximum<2000>, Traits::Default<70>, Traits::Unit<'Hz'>> {};
        class PitchMaxFreq : public LinearFloat::Modify<Traits::Minimum<100>, Traits::Maximum<10000>, Traits::Default<2000>, Traits::Unit<'Hz'>> {};
        class TuneTolerance : public LinearFloat::Modify<Traits::Minimum<0>, Traits::Maximum<50>, Traits::Default<0>, Traits::Unit<'Hz'>> {};
        class RetuneTime : public LinearUnsignedInteger::Modify<Traits::Minimum<0>, Traits::Maximum<500>, Traits::Default<50>, Traits::Unit<'ms'>> {};
        class VibratoDelay : public LinearUnsignedInteger::Modify<Traits::Minimum<0>, Traits::Maximum<1000>, Traits::Default<100>, Traits::Unit<'ms'>> {};
        class VibratoPeriod : public LinearUnsignedInteger::Modify<Traits::Minimum<10>, Traits::Maximum<250>, Traits::Default<100>, Traits::Unit<'ms'>> {};
        class VibratoDepth : public LinearUnsignedInteger::Modify<Traits::Minimum<0>, Traits::Maximum<100>, Traits::Default<50>, Traits::Unit<'"'>> {};
        class PitchShift : public SymmetricInteger::Modify<Traits::MaximumOffset<1200>, Traits::Default<0>, Traits::Unit<'"'>> {};

        LE_DEFINE_PARAMETERS(
            Key,
            SpringType,
            Semi01, Semi02, Semi03, Semi04, Semi05, Semi06, Semi07, Semi08, Semi09, Semi10, Semi11, Semi12,
            BypassSemi01, BypassSemi02, BypassSemi03, BypassSemi04, BypassSemi05, BypassSemi06, BypassSemi07, BypassSemi08, BypassSemi09, BypassSemi10, BypassSemi11, BypassSemi12,
            Vibrato,
            PitchMinFreq,
            PitchMaxFreq,
            TuneTolerance,
            RetuneTime,
            VibratoDelay,
            VibratoPeriod,
            VibratoDepth,
            PitchShift
        );
    #else // LE_SIMPLE_TUNEWORX
        LE_DEFINE_PARAMETERS(
            Key,
            Semi01, Semi02, Semi03, Semi04, Semi05, Semi06, Semi07, Semi08, Semi09, Semi10, Semi11, Semi12
        );
    #endif // LE_SIMPLE_TUNEWORX

        /// \typedef Key
        /// \brief chromatic scale root tone (default "A").
        /// \details
        ///   - A  : set root tone to A.
        ///   - Ais: set root tone to Ais.
        ///   - B  : set root tone to B.
        ///   - C  : set root tone to C.
        ///   - Cis: set root tone to Cis.
        ///   - D  : set root tone to D.
        ///   - Dis: set root tone to Dis.
        ///   - E  : set root tone to E.
        ///   - F  : set root tone to F.
        ///   - Fis: set root tone to Fis.
        ///   - G  : set root tone to G.
        ///   - Gis: set root tone to Gis.
		/// \typedef SpringType
		/// \brief Type of vibrato.
        /// \typedef Semi01
        /// \brief Snap to semitone  1 on the chromatic scale.
        /// \typedef Semi02
        /// \brief Snap to semitone  2 on the chromatic scale.
        /// \typedef Semi03
        /// \brief Snap to semitone  3 on the chromatic scale.
        /// \typedef Semi04
        /// \brief Snap to semitone  4 on the chromatic scale.
        /// \typedef Semi05
        /// \brief Snap to semitone  5 on the chromatic scale.
        /// \typedef Semi06
        /// \brief Snap to semitone  6 on the chromatic scale.
        /// \typedef Semi07
        /// \brief Snap to semitone  7 on the chromatic scale.
        /// \typedef Semi08
        /// \brief Snap to semitone  8 on the chromatic scale.
        /// \typedef Semi09
        /// \brief Snap to semitone  9 on the chromatic scale.
        /// \typedef Semi10
        /// \brief Snap to semitone 10 on the chromatic scale.
        /// \typedef Semi11
        /// \brief Snap to semitone 11 on the chromatic scale.
        /// \typedef Semi12
        /// \brief Snap to semitone 12 on the chromatic scale.
		/// \typedef BypassSemi01
		/// \brief Do not autotune if detected pitch is closest to semitone  1 on the chromatic scale.
        /// \typedef BypassSemi02
        /// \brief Do not autotune if detected pitch is closest to semitone  2 on the chromatic scale.
        /// \typedef BypassSemi03
        /// \brief Do not autotune if detected pitch is closest to semitone  3 on the chromatic scale.
        /// \typedef BypassSemi04
        /// \brief Do not autotune if detected pitch is closest to semitone  4 on the chromatic scale.
        /// \typedef BypassSemi05
        /// \brief Do not autotune if detected pitch is closest to semitone  5 on the chromatic scale.
        /// \typedef BypassSemi06
        /// \brief Do not autotune if detected pitch is closest to semitone  6 on the chromatic scale.
        /// \typedef BypassSemi07
        /// \brief Do not autotune if detected pitch is closest to semitone  7 on the chromatic scale.
        /// \typedef BypassSemi08
        /// \brief Do not autotune if detected pitch is closest to semitone  8 on the chromatic scale.
        /// \typedef BypassSemi09
        /// \brief Do not autotune if detected pitch is closest to semitone  9 on the chromatic scale.
        /// \typedef BypassSemi10
        /// \brief Do not autotune if detected pitch is closest to semitone 10 on the chromatic scale.
        /// \typedef BypassSemi11
        /// \brief Do not autotune if detected pitch is closest to semitone 11 on the chromatic scale.
		/// \typedef BypassSemi12
		/// \brief Do not autotune if detected pitch is closest to semitone 12 on the chromatic scale.
		/// \typedef Vibrato
		/// \brief Add vibrato to output signal.
		/// \typedef VibratoDelay
		/// \brief Waits for signal to be stable at a certain tone before
		/// vibrato is applied.
		/// \typedef VibratoPeriod
		/// \brief Period of added vibrato in ms.
		/// \typedef VibratoDepth
		/// \brief Maximum vibrato pitch variation.
		/// \typedef PitchMinFreq
		/// \brief Searches for pitch only at frequencies higher than
		/// PitchMinFreq.
		/// \typedef PitchMaxFreq
		/// \brief Searches for pitch only at frequencies lower than
		/// PitchMaxFreq.
		/// \typedef TuneTolerance
		/// \brief Do not autotune if the detected pitch is closer to the
		/// targeted note than desired tolerance in Hz.
		/// \typedef RetuneTime
		/// \brief Set time for autotune in ms (0 = instant change, "Cher
		/// effect").
		/// \typedef PitchShift
		/// \brief Pitch shifts output by the specified number of cents.

        static bool const usesSideChannel = false;
        static char const description[];
    };
} // namespace Detail

////////////////////////////////////////////////////////////////////////////////
///
/// \class TuneWorx
///
/// \ingroup Effects
///
/// \brief Auto-tuner.
///
/// This is the classic Autotune effect. The main channel's pitch is detected
/// and shifted to the nearest selected semitone.
///
////////////////////////////////////////////////////////////////////////////////

struct TuneWorx : Detail::TuneWorxBase
{
    static char const title[];
};


////////////////////////////////////////////////////////////////////////////////
///
/// \class TuneWorxPVD
///
/// \ingroup Effects
///
/// \brief Auto-tuner.
///
////////////////////////////////////////////////////////////////////////////////

struct TuneWorxPVD : Detail::TuneWorxBase
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

#endif // tuneWorx_hpp
