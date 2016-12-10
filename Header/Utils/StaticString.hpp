/// \file    StaticString.hpp
/// \date    01/12/2016
/// \brief   Contains all static strings
/// \author  Aredhele
/// \version 0.1.0

#ifndef __STATIC_STRING_HPP
#define __STATIC_STRING_HPP

/// \class  StaticString
/// \brief  Contains all static strings
class StaticString
{
public:

    // Type shortcut
    using CSTR = const char *;

    // Container key error
    static constexpr CSTR STATIC_FAILURE_CKNF  = "[error] Unable to find the key in the container";
    static constexpr CSTR STATIC_FAILURE_CKAE  = "[error] The key already exists in the container";
    static constexpr CSTR STATIC_FAILURE_FNF   = "[error] Unable to load resource, file not found";
};

#endif // __STATIC_STRING_HPP
