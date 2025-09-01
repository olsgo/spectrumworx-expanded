////////////////////////////////////////////////////////////////////////////////
///
/// effectNames.cpp
/// ---------------
///
/// Copyright (c) 2011 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#include "allEffects.hpp"
#include "effectNames.hpp"

#include "le/utility/platformSpecifics.hpp"

#include "boost/range/algorithm/find.hpp"
#include "boost/utility/string_ref.hpp"

#pragma warning( push )
#pragma warning( disable : 4512 ) // Assignment operator could not be generated.
#include <array>
#pragma warning( pop )
#include <cstdint>
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

LE_OPTIMIZE_FOR_SIZE_BEGIN()

#pragma warning( push )
#pragma warning( disable : 4512 ) // Assignment operator could not be generated.

namespace
{
using EffectNames = std::array<char const * LE_RESTRICT const, 57>;

LE_MSVC_SPECIFIC( LE_WEAK_SYMBOL_CONST )
EffectNames const effectNames =
{{
	Effects::PitchShifter::title,
	Effects::PitchFollower::title,
	Effects::TuneWorx::title,
	Effects::PitchMagnet::title,
	Effects::SumoPitch::title,
	Effects::PitchSpring::title,
	Effects::Octaver::title,
	Effects::Bandpass::title,
	Effects::Bandstop::title,
	Effects::AhAh::title,
	Effects::Smoother::title,
	Effects::Sharper::title,
	Effects::CentroidExtractor::title,
	Effects::Tonal::title,
	Effects::Atonal::title,
	Effects::Freeze::title,
	Effects::Slicer::title,
	Effects::Wobbler::title,
	Effects::Reverser::title,
	Effects::Imploder::title,
	Effects::Exploder::title,
	Effects::Frecho::title,
	Effects::Frevcho::title,
	Effects::Freqverb::title,
	Effects::Robotizer::title,
	Effects::Whisperer::title,
	Effects::Phasevolution::title,
	Effects::Phlip::title,
	Effects::Gain::title,
	Effects::Exaggerator::title,
	Effects::Denoiser::title,
	Effects::QuietBoost::title,
	Effects::Freqnamics::title,
	Effects::TalkingWind::title,
	Effects::Convolver::title,
	Effects::Ethereal::title,
	Effects::Vaxateer::title,
	Effects::Shapeless::title,
	Effects::Colorifer::title,
	Effects::Merger::title,
	Effects::Blender::title,
	Effects::Inserter::title,
	Effects::Burrito::title,
	Effects::PhaseVocoderAnalysis::title,
	Effects::PVPitchShifter::title,
	Effects::PitchFollowerPVD::title,
	Effects::TuneWorxPVD::title,
	Effects::PitchMagnetPVD::title,
	Effects::PitchSpringPVD::title,
	Effects::PVImploder::title,
	Effects::PVExploder::title,
	Effects::PhaseVocoderSynthesis::title,
	Effects::Armonizer::title,
	Effects::SlewLimiter::title,
	Effects::Shifter::title,
	Effects::Swappah::title,
	Effects::Quantizer::title,

}};

} // anonymous namespace

LE_COLD
char const * LE_FASTCALL effectName( std::uint8_t const effectIndex )
{
    return effectNames[ effectIndex ];
}

LE_COLD
std::int8_t LE_FASTCALL effectIndex( boost::string_ref const effectName )
{
    EffectNames::const_iterator const pFoundEffectName( boost::find( effectNames, effectName ) );
    auto const index( static_cast<std::uint8_t>( pFoundEffectName - effectNames.begin() ) );
    if ( index == effectNames.size() )
        return -1;
    return index;
}

#pragma warning( pop )

LE_OPTIMIZE_FOR_SIZE_END()

//------------------------------------------------------------------------------
} // namespace Effects
//------------------------------------------------------------------------------
} // namespace SW
//------------------------------------------------------------------------------
} // namespace LE
//------------------------------------------------------------------------------
