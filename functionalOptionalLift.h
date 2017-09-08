/*
    Copyright 2018 Krzysztof Karbowiak
*/

#ifndef FUNCTIONAL_OPTIONAL_LIFT_H__DDK
#define FUNCTIONAL_OPTIONAL_LIFT_H__DDK

#include <optional>
#include <functional>


namespace functional
{
    template<typename T, typename U>
    std::function<std::optional<T> (std::optional<U>)> lift(std::function<T (U)> f);
}

namespace functional
{
////////////////////////////////////////////////////////////////////////////////
template<typename T, typename U>
inline std::function<std::optional<T> (std::optional<U>)> lift(std::function<T (U)> f)
{
    return [f](auto arg)
    {
        return arg
            ? std::optional<T>(f(*arg))
            : std::optional<T>();
    };
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* FUNCTIONAL_OPTIONAL_LIFT_H__DDK */
