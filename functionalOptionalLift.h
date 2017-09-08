/*
    Copyright 2018 Krzysztof Karbowiak
*/

#ifndef FUNCTIONAL_OPTIONAL_LIFT_H__DDK
#define FUNCTIONAL_OPTIONAL_LIFT_H__DDK

#include <boost/optional.hpp>
#include <functional>


namespace functional
{
    template<typename T, typename U>
    std::function<boost::optional<T> (boost::optional<U>)> lift(std::function<T (U)> f);
}

namespace functional
{
////////////////////////////////////////////////////////////////////////////////
template<typename T, typename U>
inline std::function<boost::optional<T> (boost::optional<U>)> lift(std::function<T (U)> f)
{
    return [f](auto arg)
    {
        return arg
            ? boost::optional<T>(f(*arg))
            : boost::optional<T>();
    };
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* FUNCTIONAL_OPTIONAL_LIFT_H__DDK */
