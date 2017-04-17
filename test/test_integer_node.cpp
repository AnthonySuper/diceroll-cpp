#include <catch.hpp>
#include "integer_node.hpp"

using namespace Diceroll;

TEST_CASE("The value works", "[IntegerNode]") {
    IntegerNode node = 2;
    REQUIRE(node.value() == 2);
}

TEST_CASE("The distribution is uniform", "[IntegerNode]") {
    IntegerNode node = 2;
    const Distribution& dist = node.distribution();
    REQUIRE(dist[2] == Approx(1));
    REQUIRE(dist[1] == 0);
}
