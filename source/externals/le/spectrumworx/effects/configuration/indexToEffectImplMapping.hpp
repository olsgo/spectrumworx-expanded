////////////////////////////////////////////////////////////////////////////////
///
/// \file indexToEffectImplMapping.hpp
/// ----------------------------------
///
/// Copyright (c) 2009 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef indexToEffectImplMapping_hpp__A27FC4FD_E1A2_424F_97E4_17387681054F
#define indexToEffectImplMapping_hpp__A27FC4FD_E1A2_424F_97E4_17387681054F
#pragma once
//------------------------------------------------------------------------------
#include "allEffectImpls.hpp"
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

template <unsigned int index>
struct ImplForIndex;

template <> struct ImplForIndex<0> { typedef PitchShifterImpl type; };
template <> struct ImplForIndex<1> { typedef PitchFollowerImpl type; };
template <> struct ImplForIndex<2> { typedef TuneWorxImpl type; };
template <> struct ImplForIndex<3> { typedef PitchMagnetImpl type; };
template <> struct ImplForIndex<4> { typedef SumoPitchImpl type; };
template <> struct ImplForIndex<5> { typedef PitchSpringImpl type; };
template <> struct ImplForIndex<6> { typedef OctaverImpl type; };
template <> struct ImplForIndex<7> { typedef BandpassImpl type; };
template <> struct ImplForIndex<8> { typedef BandstopImpl type; };
template <> struct ImplForIndex<9> { typedef AhAhImpl type; };
template <> struct ImplForIndex<10> { typedef SmootherImpl type; };
template <> struct ImplForIndex<11> { typedef SharperImpl type; };
template <> struct ImplForIndex<12> { typedef CentroidExtractorImpl type; };
template <> struct ImplForIndex<13> { typedef TonalImpl type; };
template <> struct ImplForIndex<14> { typedef AtonalImpl type; };
template <> struct ImplForIndex<15> { typedef FreezeImpl type; };
template <> struct ImplForIndex<16> { typedef SlicerImpl type; };
template <> struct ImplForIndex<17> { typedef WobblerImpl type; };
template <> struct ImplForIndex<18> { typedef ReverserImpl type; };
template <> struct ImplForIndex<19> { typedef ImploderImpl type; };
template <> struct ImplForIndex<20> { typedef ExploderImpl type; };
template <> struct ImplForIndex<21> { typedef FrechoImpl type; };
template <> struct ImplForIndex<22> { typedef FrevchoImpl type; };
template <> struct ImplForIndex<23> { typedef FreqverbImpl type; };
template <> struct ImplForIndex<24> { typedef RobotizerImpl type; };
template <> struct ImplForIndex<25> { typedef WhispererImpl type; };
template <> struct ImplForIndex<26> { typedef PhasevolutionImpl type; };
template <> struct ImplForIndex<27> { typedef PhlipImpl type; };
template <> struct ImplForIndex<28> { typedef GainImpl type; };
template <> struct ImplForIndex<29> { typedef ExaggeratorImpl type; };
template <> struct ImplForIndex<30> { typedef DenoiserImpl type; };
template <> struct ImplForIndex<31> { typedef QuietBoostImpl type; };
template <> struct ImplForIndex<32> { typedef FreqnamicsImpl type; };
template <> struct ImplForIndex<33> { typedef TalkingWindImpl type; };
template <> struct ImplForIndex<34> { typedef ConvolverImpl type; };
template <> struct ImplForIndex<35> { typedef EtherealImpl type; };
template <> struct ImplForIndex<36> { typedef VaxateerImpl type; };
template <> struct ImplForIndex<37> { typedef ShapelessImpl type; };
template <> struct ImplForIndex<38> { typedef ColoriferImpl type; };
template <> struct ImplForIndex<39> { typedef MergerImpl type; };
template <> struct ImplForIndex<40> { typedef BlenderImpl type; };
template <> struct ImplForIndex<41> { typedef InserterImpl type; };
template <> struct ImplForIndex<42> { typedef BurritoImpl type; };
template <> struct ImplForIndex<43> { typedef PhaseVocoderAnalysisImpl type; };
template <> struct ImplForIndex<44> { typedef PVPitchShifterImpl type; };
template <> struct ImplForIndex<45> { typedef PitchFollowerPVDImpl type; };
template <> struct ImplForIndex<46> { typedef TuneWorxPVDImpl type; };
template <> struct ImplForIndex<47> { typedef PitchMagnetPVDImpl type; };
template <> struct ImplForIndex<48> { typedef PitchSpringPVDImpl type; };
template <> struct ImplForIndex<49> { typedef PVImploderImpl type; };
template <> struct ImplForIndex<50> { typedef PVExploderImpl type; };
template <> struct ImplForIndex<51> { typedef PhaseVocoderSynthesisImpl type; };
template <> struct ImplForIndex<52> { typedef ArmonizerImpl type; };
template <> struct ImplForIndex<53> { typedef SlewLimiterImpl type; };
template <> struct ImplForIndex<54> { typedef ShifterImpl type; };
template <> struct ImplForIndex<55> { typedef SwappahImpl type; };
template <> struct ImplForIndex<56> { typedef QuantizerImpl type; };


//------------------------------------------------------------------------------
} // namespace Effects
//------------------------------------------------------------------------------
} // namespace SW
//------------------------------------------------------------------------------
} // namespace LE
//------------------------------------------------------------------------------
#endif // indexToEffectMapping_hpp
