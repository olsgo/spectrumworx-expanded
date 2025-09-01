////////////////////////////////////////////////////////////////////////////////
///
/// \file effectIndexToGroupMapping.hpp
/// -----------------------------------
///
/// Copyright (c) 2011 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef effectIndexToGroupMapping_hpp__254A1D12_F9E2_40C8_B703_2E7EF2A152BE
#define effectIndexToGroupMapping_hpp__254A1D12_F9E2_40C8_B703_2E7EF2A152BE
#pragma once
//------------------------------------------------------------------------------
#include "allEffects.hpp"
#include "effectGroups.hpp"

#include "boost/mpl/vector/vector10.hpp"
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

template <unsigned int effectIndex>
struct Group;

template <> struct Group<0> { typedef ModuleGroups::Pitch type; };
template <> struct Group<1> { typedef ModuleGroups::Pitch type; };
template <> struct Group<2> { typedef ModuleGroups::Pitch type; };
template <> struct Group<3> { typedef ModuleGroups::Pitch type; };
template <> struct Group<4> { typedef ModuleGroups::Pitch type; };
template <> struct Group<5> { typedef ModuleGroups::Pitch type; };
template <> struct Group<6> { typedef ModuleGroups::Pitch type; };
template <> struct Group<7> { typedef ModuleGroups::Timbre type; };
template <> struct Group<8> { typedef ModuleGroups::Timbre type; };
template <> struct Group<9> { typedef ModuleGroups::Timbre type; };
template <> struct Group<10> { typedef ModuleGroups::Timbre type; };
template <> struct Group<11> { typedef ModuleGroups::Timbre type; };
template <> struct Group<12> { typedef ModuleGroups::Timbre type; };
template <> struct Group<13> { typedef ModuleGroups::Timbre type; };
template <> struct Group<14> { typedef ModuleGroups::Timbre type; };
template <> struct Group<15> { typedef ModuleGroups::Time type; };
template <> struct Group<16> { typedef ModuleGroups::Time type; };
template <> struct Group<17> { typedef ModuleGroups::Time type; };
template <> struct Group<18> { typedef ModuleGroups::Time type; };
template <> struct Group<19> { typedef ModuleGroups::Time type; };
template <> struct Group<20> { typedef ModuleGroups::Time type; };
template <> struct Group<21> { typedef ModuleGroups::Space type; };
template <> struct Group<22> { typedef ModuleGroups::Space type; };
template <> struct Group<23> { typedef ModuleGroups::Space type; };
template <> struct Group<24> { typedef ModuleGroups::Phase type; };
template <> struct Group<25> { typedef ModuleGroups::Phase type; };
template <> struct Group<26> { typedef ModuleGroups::Phase type; };
template <> struct Group<27> { typedef ModuleGroups::Phase type; };
template <> struct Group<28> { typedef ModuleGroups::Loudness type; };
template <> struct Group<29> { typedef ModuleGroups::Loudness type; };
template <> struct Group<30> { typedef ModuleGroups::Loudness type; };
template <> struct Group<31> { typedef ModuleGroups::Loudness type; };
template <> struct Group<32> { typedef ModuleGroups::Loudness type; };
template <> struct Group<33> { typedef ModuleGroups::Combine type; };
template <> struct Group<34> { typedef ModuleGroups::Combine type; };
template <> struct Group<35> { typedef ModuleGroups::Combine type; };
template <> struct Group<36> { typedef ModuleGroups::Combine type; };
template <> struct Group<37> { typedef ModuleGroups::Combine type; };
template <> struct Group<38> { typedef ModuleGroups::Combine type; };
template <> struct Group<39> { typedef ModuleGroups::Combine type; };
template <> struct Group<40> { typedef ModuleGroups::Combine type; };
template <> struct Group<41> { typedef ModuleGroups::Combine type; };
template <> struct Group<42> { typedef ModuleGroups::Combine type; };
template <> struct Group<43> { typedef ModuleGroups::PVD type; };
template <> struct Group<44> { typedef ModuleGroups::PVD type; };
template <> struct Group<45> { typedef ModuleGroups::PVD type; };
template <> struct Group<46> { typedef ModuleGroups::PVD type; };
template <> struct Group<47> { typedef ModuleGroups::PVD type; };
template <> struct Group<48> { typedef ModuleGroups::PVD type; };
template <> struct Group<49> { typedef ModuleGroups::PVD type; };
template <> struct Group<50> { typedef ModuleGroups::PVD type; };
template <> struct Group<51> { typedef ModuleGroups::PVD type; };
template <> struct Group<52> { typedef ModuleGroups::Misc type; };
template <> struct Group<53> { typedef ModuleGroups::Misc type; };
template <> struct Group<54> { typedef ModuleGroups::Misc type; };
template <> struct Group<55> { typedef ModuleGroups::Misc type; };
template <> struct Group<56> { typedef ModuleGroups::Misc type; };


typedef boost::mpl::vector9
<
	ModuleGroups::Pitch,
	ModuleGroups::Timbre,
	ModuleGroups::Time,
	ModuleGroups::Space,
	ModuleGroups::Phase,
	ModuleGroups::Loudness,
	ModuleGroups::Combine,
	ModuleGroups::PVD,
	ModuleGroups::Misc
> Groups;

//------------------------------------------------------------------------------
} // namespace Effects
//------------------------------------------------------------------------------
} // namespace SW
//------------------------------------------------------------------------------
} // namespace LE
//------------------------------------------------------------------------------
#endif // effectIndexToGroupMapping_hpp
