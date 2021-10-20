#include "catch.hpp"
#include "Stack.hpp"

TEST_CASE("Access the top of the empty stack", "[Stack]")
{
    Stack<int> s;

    REQUIRE_THROWS_AS(s.peek(), std::range_error);
    REQUIRE(s.size() == 0);
    REQUIRE(s.isEmpty());
}

TEST_CASE("Test push() method", "[stack]") {
    Stack<int> s;
    s.push(10);
    REQUIRE_FALSE(s.isEmpty());
    REQUIRE(s.size() == 1);
    REQUIRE(s.peek() == 10);
    for (int i = 0; i < 100; i++) {
        s.push(i);
    }
    REQUIRE(s.size() == 101);
}

TEST_CASE("Test pop() method", "[stack]") {
    Stack<int> s;
    REQUIRE_FALSE(s.pop());
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    REQUIRE(s.size() == 4);
    REQUIRE(s.pop());
    REQUIRE(s.size() == 3);
    REQUIRE(s.pop());
    REQUIRE(s.size() == 2);
    REQUIRE(s.pop());
    REQUIRE(s.size() == 1);
    REQUIRE(s.pop());
    REQUIRE(s.size() == 0);
}

TEST_CASE("Test copy constructor", "[stack]") {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    Stack<int> s1(s);
    REQUIRE(s1.peek() == s.peek());
    s.pop();
    REQUIRE(s1.peek() == 5);
    REQUIRE(s.peek() == 4);
}