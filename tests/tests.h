#pragma once
#include <catch2/catch.hpp>
#include "../src/math/point.h"
#include "../src/math/mathutil.h"

TEST_CASE("Adding Points") {
	//Be careful of floating point precision!
	//Using aboutEquals which compares doubles with an epsilon

	Point p1(1, 1, 1);
	Point p2(1, 1, 1);
	Point result = p1 + p2;
	REQUIRE(aboutEquals(result.x, 2));
	REQUIRE(aboutEquals(result.y, 2));
	REQUIRE(aboutEquals(result.z, 2));

	p1 = Point(1.5, 5, 7);
	p2 = Point(2, 4.8, 5);
	result = p1 + p2;
	REQUIRE(aboutEquals(result.x, 3.5));
	REQUIRE(aboutEquals(result.y, 9.8));
	REQUIRE(aboutEquals(result.z, 12));
}