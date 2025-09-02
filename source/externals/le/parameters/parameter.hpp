////////////////////////////////////////////////////////////////////////////////
///
/// \file parameter.hpp
/// -------------------
///
/// Copyright (c) 2009 - 2024. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
#ifndef parameter_hpp__B49E51E6_E59F_4C49_A702_B6533579846D
#define parameter_hpp__B49E51E6_E59F_4C49_A702_B6533579846D
#pragma once
//------------------------------------------------------------------------------
#include "le/utility/assert.hpp"
#include <string_view>

//------------------------------------------------------------------------------
namespace LE
{
//------------------------------------------------------------------------------
namespace Parameters
{
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
///
/// \class Parameter
///
///   Implements the Parameter concept based on the specified traits.
///
///   None of its member functions may throw.
///
////////////////////////////////////////////////////////////////////////////////

template <typename ValueType, ValueType Min, ValueType Max, ValueType Default, typename Unit = std::string_view>
class Parameter
{
public:
    using value_type = ValueType;
    using param_type = ValueType;
    using binary_type = value_type;

public:
    // Intentional implicit conversion.
    Parameter( param_type initialValue = Default )
    {
        setValue( initialValue );
    }

    value_type const & getValue() const { return value_;  }
    void               setValue( param_type value ) { value_ = value; }

    void reset() { setValue( Default ); }

public:
    operator value_type const &() const { return getValue(); }

    Parameter & operator++()
    {
        ++value_;
        return *this;
    }

    Parameter & operator--()
    {
        --value_;
        return *this;
    }

    bool operator!=( param_type other ) const { return this->getValue() != other; }

    static constexpr value_type minimum() { return Min; }
    static constexpr value_type maximum() { return Max; }
    static constexpr value_type default_() { return Default; }
    static constexpr Unit unit() { return {}; }

protected:
    value_type value_;
};

//------------------------------------------------------------------------------
} // namespace Parameters
//------------------------------------------------------------------------------
} // namespace LE
//------------------------------------------------------------------------------
#endif // parameter_hpp
