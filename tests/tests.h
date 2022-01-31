#pragma once
#include <catch2/catch.hpp>
#include "../src/math/point.h"

TEST_CASE("Adding Points") {
	Point p1(1, 1, 1);
	Point p2(1, 1, 1);
	Point result = p1 + p2;
	REQUIRE(result.x == 2);
	REQUIRE(result.y == 2);
	REQUIRE(result.z == 2);
}