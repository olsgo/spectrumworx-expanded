////////////////////////////////////////////////////////////////////////////////
///
/// effectTypeNames.cpp
/// -------------------
///
/// Copyright (c) 2013 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
#ifdef LE_SW_SDK_BUILD //...mrmlj...not needed for plugin builds and generates dubious compiler errors with msvc10...
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
using EffectTypeNames = std::array<char const * LE_RESTRICT const, 57>;

LE_MSVC_SPECIFIC( LE_WEAK_SYMBOL_CONST )
EffectNames const effectTypeNames =
{{
	"PitchShifter",
	"PitchFollower",
	"TuneWorx",
	"PitchMagnet",
	"SumoPitch",
	"PitchSpring",
	"Octaver",
	"Bandpass",
	"Bandstop",
	"AhAh",
	"Smoother",
	"Sharper",
	"CentroidExtractor",
	"Tonal",
	"Atonal",
	"Freeze",
	"Slicer",
	"Wobbler",
	"Reverser",
	"Imploder",
	"Exploder",
	"Frecho",
	"Frevcho",
	"Freqverb",
	"Robotizer",
	"Whisperer",
	"Phasevolution",
	"Phlip",
	"Gain",
	"Exaggerator",
	"Denoiser",
	"QuietBoost",
	"Freqnamics",
	"TalkingWind",
	"Convolver",
	"Ethereal",
	"Vaxateer",
	"Shapeless",
	"Colorifer",
	"Merger",
	"Blender",
	"Inserter",
	"Burrito",
	"PhaseVocoderAnalysis",
	"PVPitchShifter",
	"PitchFollowerPVD",
	"TuneWorxPVD",
	"PitchMagnetPVD",
	"PitchSpringPVD",
	"PVImploder",
	"PVExploder",
	"PhaseVocoderSynthesis",
	"Armonizer",
	"SlewLimiter",
	"Shifter",
	"Swappah",
	"Quantizer",

}};
} // anonymous namespace

LE_COLD
char const * LE_FASTCALL effectIndex2TypeName( std::uint8_t const effectIndex )
{
    return effectTypeNames[ effectIndex ];
}

LE_COLD
std::uint8_t LE_FASTCALL effectTypeName2Index( boost::string_ref const effectTypeName )
{
    EffectTypeNames::const_iterator const pFoundEffectTypeName( boost::find( effectTypeNames, effectTypeName ) );
    //...mrmlj...required by DoxyHelper
    //BOOST_ASSERT_MSG( pFoundEffectTypeName != effectTypeNames.end(), "Effect not found." );
    if ( pFoundEffectTypeName == effectTypeNames.end() )
        return std::uint8_t( -1 );
    auto const index( static_cast<std::uint8_t>( pFoundEffectTypeName - effectTypeNames.begin() ) );
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
#endif // LE_SW_SDK_BUILD
