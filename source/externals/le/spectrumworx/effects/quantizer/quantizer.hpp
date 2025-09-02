////////////////////////////////////////////////////////////////////////////////
///
/// \file quantizer.hpp
/// -------------------
///
/// Copyright (c) 2009 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef quantizer_hpp__3DC36D0D_02D4_4EBE_A133_5CAA7A852469
#define quantizer_hpp__3DC36D0D_02D4_4EBE_A133_5CAA7A852469
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
/// \class Quantizer
///
/// \ingroup Effects
///
/// \brief Quantizes the spectrum.  
///
/// Quantizes the spectrum. The range is cut into bands of a given width, and 
/// all frequencies in any region will have the same amplitude (determined by 
/// the first frequency component in that band). The Origami parameter allows 
/// frequency components to differ from the first one, but to linearly change
/// towards the end of the band. 
/// 
////////////////////////////////////////////////////////////////////////////////

struct Quantizer
{
    class Width : public LinearUnsignedInteger::Modify<Traits::Minimum<0>, Traits::Maximum<2000>, Traits::Default<500>, Traits::Unit<' Hz'>> {};
    class Origami : public LinearUnsignedInteger::Modify<Traits::Minimum<0>, Traits::Maximum<100>, Traits::Default<0>, Traits::Unit<' %'> > {};

    LE_DEFINE_PARAMETERS(
        Width,
        Origami
    );

    /// \typedef Width
    /// \brief Width of the frequency region to be quantized.
    /// \typedef Origami
    /// \brief Amount of linear ascending towards the end of the band.


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

#endif // quantizer_hpp
