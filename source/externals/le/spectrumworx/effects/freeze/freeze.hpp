////////////////////////////////////////////////////////////////////////////////
///
/// \file freeze.hpp
/// ----------------
///
/// Copyright (c) 2009 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef freeze_hpp__1C855F51_D0CA_48B9_8F40_4B259941C1F9
#define freeze_hpp__1C855F51_D0CA_48B9_8F40_4B259941C1F9
#if defined( _MSC_VER ) && !defined( DOXYGEN_ONLY )
#pragma once
#endif // MSVC && !Doxygen
//------------------------------------------------------------------------------
#include "le/spectrumworx/effects/parameters.hpp"
#include "le/parameters/linear/parameter.hpp"
#include "le/parameters/trigger/parameter.hpp"

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
/// \class Freeze
///
/// \ingroup Effects
///
/// \brief Time freeze with smooth transition between normal and frozen state.
///
////////////////////////////////////////////////////////////////////////////////

struct Freeze
{
    ////////////////////////////////////////////////////////////////////////////
    // Parameters
    ////////////////////////////////////////////////////////////////////////////

    class FreezeTrigger : public TriggerParameter {};
    class MeltTrigger : public TriggerParameter {};
    class TransitionTime : public LinearUnsignedInteger::Modify<Traits::Minimum<0>, Traits::Maximum<10000>, Traits::Default<500>, Traits::Unit<' ms'>> {};

    LE_DEFINE_PARAMETERS(
        FreezeTrigger,
        MeltTrigger,
        TransitionTime
    );

    /// \typedef FreezeTrigger
    /// \brief Initiates the freezing process.
    /// \typedef MeltTrigger
    /// \brief Initiates the melting process.
    /// \typedef TransitionTime
    /// \brief Transition time between two states.


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

#endif // freeze_hpp