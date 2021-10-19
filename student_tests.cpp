#include "catch.hpp"
#include "Stack.hpp"

TEST_CASE( "Access the top of the empty stack", "[Stack]" )
{
  Stack<int> s;
  
  REQUIRE_THROWS_AS(s.top(), std::range_error);
}
