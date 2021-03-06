#include <catch.hpp>
#include <distribution.hpp>

using namespace Diceroll;

TEST_CASE("Distribution::uniformRange works", "[Distribution]") {
    auto d = Distribution::uniformRange(1, 6);
    REQUIRE(d[0] == 0.0);
    REQUIRE(d[1] == Approx(1.0 / 6.0));
}

TEST_CASE("Distribution::average works", "[Distribution]") {

    auto d = Distribution::uniformRange(1, 20);
    REQUIRE(d.average() == Approx(10.50));
}

TEST_CASE("Distribution::max works", "[Distribution]") {
    auto d = Distribution::uniformRange(1, 20);
    REQUIRE(d.max() == 20);
}

TEST_CASE("Distribution::min works", "[Distribution]") {
    auto d = Distribution::uniformRange(1, 20);
    REQUIRE(d.min() == 1);
}

TEST_CASE("Distribution::convolveAdd 2d20", "[Distribution]") {
    auto d20 = Distribution::uniformRange(1, 20);
    auto both = d20.convolveAdd(d20);
    auto minPercentage = 1.0 / (20 * 20);
    REQUIRE(both[2] == Approx(minPercentage));
    REQUIRE(both[40] == Approx(minPercentage));
    REQUIRE(both.min() == 2);
    REQUIRE(both.max() == 40);
}

TEST_CASE("Convolve works", "[Distribution]") {
    auto d2 = Distribution::uniformRange(1, 2);
    auto twod2 = d2.convolve(d2, [](auto a, auto b){
        return a + b;
    });
    REQUIRE(twod2[1] == Approx(0));
    REQUIRE(twod2[2] == Approx(1.0 / 4));
    REQUIRE(twod2[3] == Approx(0.5));
    REQUIRE(twod2[4] == Approx(1.0 / 4));
}
