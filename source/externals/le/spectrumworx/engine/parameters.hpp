////////////////////////////////////////////////////////////////////////////////
///
/// \file parameters.hpp
/// --------------------
///
/// Copyright (c) 2009 - 2016. Little Endian Ltd. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
#ifndef parameters_hpp__390E5B0C_2423_463D_BAF5_4222DF433830
#define parameters_hpp__390E5B0C_2423_463D_BAF5_4222DF433830
#pragma once
//------------------------------------------------------------------------------
#include "automatableParameters.hpp"

#include "le/parameters/enumerated/parameter.hpp"
#include "le/parameters/linear/parameter.hpp"
#include "le/parameters/factoryMacro.hpp"
//------------------------------------------------------------------------------
namespace LE
{
//------------------------------------------------------------------------------
namespace SW
//------------------------------------------------------------------------------
{
namespace GlobalParameters // Automated parameters
//------------------------------------------------------------------------------
{
    using FFTSize          = Engine::FFTSize         ;
#if LE_SW_ENGINE_WINDOW_PRESUM
    using WindowSizeFactor = Engine::WindowSizeFactor;
#endif // LE_SW_ENGINE_WINDOW_PRESUM
    using OverlapFactor    = Engine::OverlapFactor   ;
    using WindowFunction   = Engine::WindowFunction  ;

#if LE_SW_ENGINE_INPUT_MODE >= 1
    enum InputModeValue { Stereo, StereoSideChain, Mono, MonoSideChain };
    class InputMode : public LE::Parameters::EnumeratedParameter<4> {};
#endif // LE_SW_ENGINE_INPUT_MODE
    //LE_ENUMERATED_PARAMETER( StreamMode, ( Always )( MIDITrigger )( MIDIGate ) ); // ...MIDI not supported yet

#if LE_SW_ENGINE_WINDOW_PRESUM
    #define LE_SW_WINDOW_SIZEFACTOR_PARAMETER() ( ( WindowSizeFactor ) )
#else
    #define LE_SW_WINDOW_SIZEFACTOR_PARAMETER()
#endif // LE_SW_ENGINE_WINDOW_PRESUM

#if LE_SW_ENGINE_INPUT_MODE >= 1
    #define LE_SW_INPUTMODE_PARAMETER() ( ( InputMode ) )
#else // LE_SW_ENGINE_INPUT_MODE
    #define LE_SW_INPUTMODE_PARAMETER()
#endif // LE_SW_ENGINE_INPUT_MODE

    class InputGain : public LE::Parameters::LinearFloat::Modify<LE::Parameters::Traits::Minimum<1>, LE::Parameters::Traits::Maximum<2000>, LE::Parameters::Traits::Default<1000>, LE::Parameters::Traits::ValuesDenominator<1000>> {};
    class OutputGain : public InputGain {};
    class MixPercentage : public LE::Parameters::LinearFloat::Modify<LE::Parameters::Traits::Minimum<0>, LE::Parameters::Traits::Maximum<1>, LE::Parameters::Traits::Default<1>> {};

    LE_DEFINE_PARAMETERS(
        InputGain,
        OutputGain,
        MixPercentage,
        FFTSize,
        OverlapFactor,
        WindowFunction
#if LE_SW_ENGINE_WINDOW_PRESUM
        , WindowSizeFactor
#endif // LE_SW_ENGINE_WINDOW_PRESUM
#if LE_SW_ENGINE_INPUT_MODE >= 1
        , InputMode
#endif // LE_SW_ENGINE_INPUT_MODE
    );

    #undef LE_SW_WINDOW_SIZEFACTOR_PARAMETER
    #undef LE_SW_INPUTMODE_PARAMETER
//------------------------------------------------------------------------------
} // namespace GlobalParameters
//------------------------------------------------------------------------------
} // namespace SW
//------------------------------------------------------------------------------
} // namespace LE
//------------------------------------------------------------------------------
#endif // parameters_hpp
