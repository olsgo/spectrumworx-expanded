////////////////////////////////////////////////////////////////////////////////
///
/// \file factoryMacro.hpp
/// ----------------------
///
/// Copyright (c) 2009 - 2024. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
#ifndef factoryMacro_hpp__8F075C97_FE9A_47F0_A01B_A3632AA17AC9
#define factoryMacro_hpp__8F075C97_FE9A_47F0_A01B_A3632AA17AC9
#pragma once
//------------------------------------------------------------------------------
#include "parameter.hpp"
#include <cstdint>
#include <tuple>
#include <utility>

//------------------------------------------------------------------------------
namespace LE
{
//------------------------------------------------------------------------------
namespace Parameters
{
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
///
/// Helper verbosity reducing macros for parameter specifications.
/// --------------------------------------------------------------
///
////////////////////////////////////////////////////////////////////////////////

template <typename T, typename Tuple>
struct IndexOfImpl;

template <typename T, typename... Us>
struct IndexOfImpl<T, std::tuple<T, Us...>> : std::integral_constant<std::size_t, 0> {};

template <typename T, typename U, typename... Us>
struct IndexOfImpl<T, std::tuple<U, Us...>> : std::integral_constant<std::size_t, 1 + IndexOfImpl<T, std::tuple<Us...>>::value> {};

#define LE_DEFINE_PARAMETERS( ... ) \
    struct Parameters                                                                  \
    {\
        using parameter_types = std::tuple<__VA_ARGS__>;                               \
        static constexpr std::size_t static_size = std::tuple_size<parameter_types>::value; \
                                                                                       \
        template <std::size_t I>
        using ParameterAt = typename std::tuple_element<I, parameter_types>::type;     \
                                                                                       \
        template <typename P>
        static constexpr std::size_t IndexOf = IndexOfImpl<P, parameter_types>::value; \
                                                                                       \
        template <typename P>
        P& get() { return std::get<P>(parameters_); }                                  \
                                                                                       \
        template <typename P>
        const P& get() const { return std::get<P>(parameters_); }                      \
                                                                                       \
        template <std::size_t I>
        auto& get() { return std::get<I>(parameters_); }                               \
                                                                                       \
        template <std::size_t I>
        const auto& get() const { return std::get<I>(parameters_); }                   \
                                                                                       \
    private:                                                                           \
        parameter_types parameters_;                                                   \
    };

//------------------------------------------------------------------------------
} // namespace Parameters
//------------------------------------------------------------------------------
} // namespace LE
//------------------------------------------------------------------------------
#endif // factoryMacro_hpp