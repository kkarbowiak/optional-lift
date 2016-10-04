#ifndef FUNCTIONAL_OPTIONAL_LIFT_H__DDK
#define FUNCTIONAL_OPTIONAL_LIFT_H__DDK

#include <boost/optional.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>


namespace functional
{
    template<typename T, typename U>
    boost::function<boost::optional<T> (boost::optional<U>)> lift(boost::function<T (U)> f);
}

namespace functional
{
namespace detail
{
    template<typename T, typename U>
    boost::optional<T> lift_helper(boost::function<T (U)> f, boost::optional<U> arg);
}
}

namespace functional
{
////////////////////////////////////////////////////////////////////////////////
template<typename T, typename U>
inline boost::function<boost::optional<T> (boost::optional<U>)> lift(boost::function<T (U)> f)
{
    return boost::bind(&detail::lift_helper<T, U>, f, _1);
}
////////////////////////////////////////////////////////////////////////////////
}

namespace functional
{
namespace detail
{
////////////////////////////////////////////////////////////////////////////////
template<typename T, typename U>
inline boost::optional<T> lift_helper(boost::function<T (U)> f, boost::optional<U> arg)
{
    return arg
        ? boost::optional<T>(f(*arg))
        : boost::optional<T>();
}
////////////////////////////////////////////////////////////////////////////////
}
}

#endif /* FUNCTIONAL_OPTIONAL_LIFT_H__DDK */
