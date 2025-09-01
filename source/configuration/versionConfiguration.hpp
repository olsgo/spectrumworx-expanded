////////////////////////////////////////////////////////////////////////////////
///
/// \file versionConfiguration.hpp
/// ------------------------------
///
/// Copyright (c) 2010 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef versionConfiguration_hpp__BB8C450C_443D_4F87_9241_44B477F0DE52
#define versionConfiguration_hpp__BB8C450C_443D_4F87_9241_44B477F0DE52
#pragma once
//------------------------------------------------------------------------------
namespace LE
{
//------------------------------------------------------------------------------
namespace SW
{
//------------------------------------------------------------------------------

#define SW_VERSION_MAJOR        3
#define SW_VERSION_MINOR        0
#define SW_VERSION_PATCH        0
#define SW_VERSION_DESCRIPTION "development"

#define SW_IS_RETAIL      0
#define SW_ENABLE_UPGRADE 0

#define SW_VERSION_STRING "3.0.0 development"

#define SW_EDITION_STRING ""

#define MB_ERROR   "SpectrumWorx" SW_EDITION_STRING " error:"
#define MB_WARNING "SpectrumWorx" SW_EDITION_STRING " warning:"

//------------------------------------------------------------------------------
} // namespace SW
//------------------------------------------------------------------------------
} // namespace LE
//------------------------------------------------------------------------------
#endif // versionConfiguration_hpp
