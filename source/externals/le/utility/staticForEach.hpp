////////////////////////////////////////////////////////////////////////////////
///
/// \file staticForEach.hpp
/// -----------------------
///
/// Copyright (c) 2010 - 2024. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef staticForEach_hpp__C3553311_E011_474C_B651_74228B0BEDCE
#define staticForEach_hpp__C3553311_E011_474C_B651_74228B0BEDCE
#pragma once
//------------------------------------------------------------------------------
#include "platformSpecifics.hpp"

#include <boost/mp11.hpp>

#include <type_traits>
#include <utility>
//------------------------------------------------------------------------------
namespace LE
{
//------------------------------------------------------------------------------
namespace Utility
{
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
//
// forEach()
// --------
//
////////////////////////////////////////////////////////////////////////////////
///
/// \brief A simpler and more efficient version of the mpl::for_each<>()
/// function. @see boost::mpl::for_each.
///
////////////////////////////////////////////////////////////////////////////////

template <typename Sequence, typename F>
void LE_FASTCALL forEach( F && f )
{
    boost::mp11::mp_for_each<Sequence>( std::forward<F>( f ) );
}


template <typename Sequence, typename Functor, typename Predicate>
typename Functor::result_type LE_FASTCALL applyFor( Functor && f, Predicate && p )
{
    using namespace boost::mp11;

    bool found = false;
    typename Functor::result_type result;

    mp_for_each<Sequence>([&](auto wrapper)
    {
        using T = typename decltype(wrapper)::type;
        if (!found && p.template operator()<T>())
        {
            result = f.template operator()<T>();
            found = true;
        }
    });

    if ( !found )
    {
        LE_UNREACHABLE_CODE();
    }

    return result;
}

//------------------------------------------------------------------------------
} // namespace Utility
//------------------------------------------------------------------------------
} // namespace LE
//------------------------------------------------------------------------------
#endif // staticForEach_hpp