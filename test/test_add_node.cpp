#include <catch.hpp>
#include "add_node.hpp"
#include "roll_node.hpp"

using namespace Diceroll;

TEST_CASE("Adds two d20s value", "[AddNode]") {
    auto n = AddNode(RollNode(20, 10), RollNode(20, 10));
    REQUIRE(n.value() == Approx(20));
}

TEST_CASE("Adds two d20s reroll", "[AddNode]") {
    auto n = AddNode(RollNode(20, 10), RollNode(20, 10));
    for(int i = 0; i < 20; ++i) {
        REQUIRE(n.reroll()->value() <= Approx(40));
        REQUIRE(n.reroll()->value() >= Approx(2));
    }
}

TEST_CASE("Adds two d2s", "[AddNode]") {
    auto n = AddNode(RollNode(2, 1), RollNode(2, 1));
    REQUIRE(n.value() == Approx(2));
}
