#pragma once
#include <catch2/catch.hpp>
#include "../math/mathutil.h"
#include "../math/vector.h"

TEST_CASE("Creating a vector from two points") {
	Point p1(0, 0, 0);
	Point p2(1, 0, 0);
	Vector v(p1, p2);
	REQUIRE(aboutEquals(v.xCom,1));
	REQUIRE(aboutEquals(v.yCom, 0));
	REQUIRE(aboutEquals(v.zCom, 0));

	//Check vector is normalized
	p1 = Point(0,0,0);
	p2 = Point(4,3,0);
	v = Vector(p1, p2);
	REQUIRE(aboutEquals(v.xCom, 4./5));
	REQUIRE(aboutEquals(v.yCom, 3./5));
	REQUIRE(aboutEquals(v.zCom, 0));


	//Check from two non-origin points
	p1 = Point(6, 1, sqrt(8));
	p2 = Point(4, 3, 0);
	v = Vector(p1, p2);
	REQUIRE(aboutEquals(v.xCom, -2. / 4));
	REQUIRE(aboutEquals(v.yCom, 2. / 4));
	REQUIRE(aboutEquals(v.zCom, -sqrt(8) / 4));
}