////////////////////////////////////////////////////////////////////////////////
///
/// \file freqnamics.hpp
/// --------------------
///
/// Copyright (c) 2009 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef freqnamics_hpp__66F9664C_18BF_4F34_9C54_83FCB44DC9F1
#define freqnamics_hpp__66F9664C_18BF_4F34_9C54_83FCB44DC9F1
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

////////////////////////////////////////////////////////////////////////////////
///
/// \class Freqnamics
///
/// \ingroup Effects
///
/// \brief Dynamics processing in the frequency domain. 
///
/// Provides dynamics processing in the frequency domain. Acts as both a limiter 
/// and a noise gate. Everything above limiter threshold is flattened, and 
/// everything below noise gate threshold is removed. 
/// 
////////////////////////////////////////////////////////////////////////////////

struct Freqnamics
{
    class LimiterThreshold : public LinearFloat::Modify<Traits::Minimum<-90>, Traits::Maximum<0>, Traits::Default<-10>, Traits::Unit<' dB'>> {};
    class NoisegateThreshold : public LinearFloat::Modify<Traits::Minimum<-90>, Traits::Maximum<0>, Traits::Default<-60>, Traits::Unit<' dB'>> {};

    LE_DEFINE_PARAMETERS(
        LimiterThreshold,
        NoisegateThreshold
    );

    /// \typedef LimiterThreshold
    /// \brief Limiter threshold.
    /// \typedef NoisegateThreshold
    /// \brief Noise gate threshold.

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

#endif // freqnamics_hpp
