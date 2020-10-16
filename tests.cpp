#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "indent.h"
#include "unindent.h"

TEST_CASE("removeLeadingSpaces(indented_str) == unindented_str") {
    CHECK(removeLeadingSpaces("       int x = 1;  ") == "int x = 1;  ");
    CHECK(removeLeadingSpaces("") == "");
    CHECK(removeLeadingSpaces("     ") == "");
    CHECK(removeLeadingSpaces("hello ") == "hello ");
    CHECK(removeLeadingSpaces("\nhello") == "hello");
    CHECK(removeLeadingSpaces("\n hello") == "hello");
    CHECK(removeLeadingSpaces("\t\thello") == "hello");
    CHECK(removeLeadingSpaces("\n") == "");
}