#include "catch/catch.hpp"

#include "functionalOptionalLift.h"

#include <boost/optional/optional_io.hpp>

#include <string>
#include <cctype>


int intFromInt(int i);
int intFromStr(std::string s);
std::string strFromInt(int i);
std::string strFromStr(std::string s);


TEST_CASE("lift int (int)", "[int][int]")
{
    typedef boost::optional<int> optint;
    std::function<optint (optint)> foo_ii = functional::lift(std::function<int (int)>(&intFromInt));
    optint o1;
    optint o2 = 3;

    REQUIRE(foo_ii(o1) == boost::none);
    REQUIRE(foo_ii(o2) == intFromInt(*o2));
}

TEST_CASE("lift int (std::string)", "[int][std::string]")
{
    typedef boost::optional<int> optint;
    typedef boost::optional<std::string> optstr;
    std::function<optint (optstr)> foo_is = functional::lift(std::function<int (std::string)>(&intFromStr));
    optstr o1;
    optstr o2 = std::string("711");

    REQUIRE(foo_is(o1) == boost::none);
    REQUIRE(foo_is(o2) == intFromStr(*o2));
}

TEST_CASE("lift std::string (int)", "[std::string][int]")
{
    typedef boost::optional<std::string> optstr;
    typedef boost::optional<int> optint;
    std::function<optstr (optint)> foo_si = functional::lift(std::function<std::string (int)>(&strFromInt));
    optint o1;
    optint o2 = 2456;

    REQUIRE(foo_si(o1) == boost::none);
    REQUIRE(foo_si(o2) == strFromInt(*o2));
}

TEST_CASE("lift std::string (std::string)", "[std::string][std::string]")
{
    typedef boost::optional<std::string> optstr;
    std::function<optstr (optstr)> foo_ss = functional::lift(std::function<std::string (std::string)>(&strFromStr));
    optstr o1;
    optstr o2 = std::string("abCdefG");

    REQUIRE(foo_ss(o1) == boost::none);
    REQUIRE(foo_ss(o2) == strFromStr(*o2));
}

int intFromInt(int i)
{
    return (2 * i);
}

int intFromStr(std::string s)
{
    return std::stoi(s);
}

std::string strFromInt(int i)
{
    return std::to_string(i);
}

std::string strFromStr(std::string s)
{
    std::string result = s;
    for (std::string::iterator i = result.begin(); i != result.end(); ++i)
    {
        *i = std::toupper(*i);
    }
    return result;
}
