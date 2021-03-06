#include <catch.hpp>
#include <roll_node.hpp>

TEST_CASE("Value construction", "[RollNode]") {
    Diceroll::RollNode roll(6, 2);
    REQUIRE(roll.value() == 2);
}

TEST_CASE("Invalid value construction", "[RollNode]") {
    REQUIRE_THROWS(std::unique_ptr<Diceroll::RollNode>(new Diceroll::RollNode(1, 10)));
}

TEST_CASE("Distribution", "[RollNode]") {
    Diceroll::RollNode roll(20);
    auto &d = roll.distribution();
    REQUIRE(d[20] == Approx(1 / 20.0));
}
