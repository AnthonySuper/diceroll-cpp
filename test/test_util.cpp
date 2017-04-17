#include "catch.hpp"
#include "util.hpp"

using namespace Diceroll;
using namespace Diceroll::Literals;

TEST_CASE("roll works", "[Util, rollDice]") {
    auto d = roll(2, 20);
    REQUIRE(d->distribution()[0] == 0);
    REQUIRE(d->distribution()[2] == Approx(1.0 / (20 * 20)));
}

TEST_CASE("_d20 literal works", "[Util, Literals]") {
    auto d = 2_d20;
    REQUIRE(d->distribution()[0] == 0);
    REQUIRE(d->distribution()[2] == Approx(1.0 / (20 * 20)));
    
}
