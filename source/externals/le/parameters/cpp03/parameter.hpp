////////////////////////////////////////////////////////////////////////////////
///
/// \file parameter.hpp
/// -------------------
///
/// Copyright © 2009 - 2015. Little Endian. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef parameter_hpp__B49E51E6_E59F_4C49_A702_B6533579846D
#define parameter_hpp__B49E51E6_E59F_4C49_A702_B6533579846D
#pragma once
//------------------------------------------------------------------------------
#include "boost/assert.hpp"
#include "boost/mpl/map/map10.hpp"
#include "boost/mpl/string.hpp"
#include "boost/preprocessor/comparison/greater.hpp"
#include "boost/preprocessor/seq/seq.hpp"
#include "boost/preprocessor/seq/enum.hpp"
#include "boost/preprocessor/seq/transform.hpp"
//------------------------------------------------------------------------------
namespace LE
{
//------------------------------------------------------------------------------
namespace Parameters
{
//------------------------------------------------------------------------------
namespace Traits
{
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
//
// Parameter "traits" (or "properties" or "options") classes.
// ----------------------------------------------------------
//
////////////////////////////////////////////////////////////////////////////////
///
/// \defgroup ParameterProperties Parameter properties
///
///   These are actually a form of 'named' parameters for the Parameter class.
/// They define their underlying type and their default value (which is used if
/// the trait/property/option is not explicitly specified in a Parameter
/// declaration.
///
////////////////////////////////////////////////////////////////////////////////
///
/// \struct Minimum
/// \ingroup ParameterProperties
///
////////////////////////////////////////////////////////////////////////////////
///
/// \struct Maximum
/// \ingroup ParameterProperties
///
////////////////////////////////////////////////////////////////////////////////
///
/// \struct Default
/// \ingroup ParameterProperties
///
////////////////////////////////////////////////////////////////////////////////
///
/// \struct ValuesDenominator
/// \ingroup ParameterProperties
///
///   A value with which the default and range values are divided to calculate
/// their real values (used for floating point type parameters, specifying them
/// as rational numbers, e.g.
/// 'real minimum value' = minimumValue / valuesDenominator.
///
////////////////////////////////////////////////////////////////////////////////

// Helper verbosity-reducing macros for Parameter trait declarations.

#define DECLARE_PARAMETER_TRAIT( name, valueType )  \
namespace Tag { struct name; }                      \
template <valueType vvalue>                         \
struct name                                         \
    :                                               \
    boost::mpl::pair                                \
    <                                               \
        Tag::name,                                  \
        boost::mpl::integral_c<valueType, vvalue>   \
    >                                               \
{}


#endif // parameter_hpp
