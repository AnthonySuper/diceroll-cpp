#include <catch.hpp>
#include "dice_expr.hpp"
#include "roll_node.hpp"

using namespace Diceroll;

TEST_CASE("It automatically converts rollNodes", "[DiceExpr]") {
    DiceExpr exp = RollNode(2);
    REQUIRE(exp->distribution().average() == Approx(1.5));
}

TEST_CASE("Addition Works", "[DiceExpr]") {
    DiceExpr expr = RollNode(2, 1);
    DiceExpr add = expr + expr;
    REQUIRE(add->value() == Approx(2));
}
