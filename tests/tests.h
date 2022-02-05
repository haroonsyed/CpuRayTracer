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

	p1 = Point(-9999.2, 555.1, 235.4645);
	p2 = Point(1, 3, -6);
	result = p1 + p2;
	REQUIRE(aboutEquals(result.x, -9998.2));
	REQUIRE(aboutEquals(result.y, 558.1));
	REQUIRE(aboutEquals(result.z, 229.4645));
}

TEST_CASE("Subtracting Points") {
	Point p1(1, 1, 1);
	Point p2(1, 1, 1);
	Point result = p1 - p2;
	REQUIRE(aboutEquals(result.x, 0));
	REQUIRE(aboutEquals(result.y, 0));
	REQUIRE(aboutEquals(result.z, 0));

	p1 = Point(1.5, 5, 7);
	p2 = Point(2, 4.8, 5);
	result = p1 - p2;
	REQUIRE(aboutEquals(result.x, -0.5));
	REQUIRE(aboutEquals(result.y, 0.2));
	REQUIRE(aboutEquals(result.z, 2));

	p1 = Point(-9999.2, 555.1, 235.4645);
	p2 = Point(1, 3, -6);
	result = p1 - p2;
	REQUIRE(aboutEquals(result.x, -10000.2));
	REQUIRE(aboutEquals(result.y, 552.1));
	REQUIRE(aboutEquals(result.z, 241.4645));
}

TEST_CASE("Multiply Point by scalar") {
	Point p1(1, 1, 1);
	Point result = 5*p1;
	REQUIRE(aboutEquals(result.x, 5));
	REQUIRE(aboutEquals(result.y, 5));
	REQUIRE(aboutEquals(result.z, 5));

	p1 = Point(1, 1, 1);
	result = p1*5; //Reverse operator
	REQUIRE(aboutEquals(result.x, 5));
	REQUIRE(aboutEquals(result.y, 5));
	REQUIRE(aboutEquals(result.z, 5));


	p1 = Point(-1, 1.5, 3);
	result = 1.5 * p1;
	REQUIRE(aboutEquals(result.x, -1.5));
	REQUIRE(aboutEquals(result.y, 2.25));
	REQUIRE(aboutEquals(result.z, 4.5));

	p1 = Point(1, 1, 3.5005);
	result = 1.1 * p1;
	REQUIRE(aboutEquals(result.z, 3.85055));
}

TEST_CASE("Divide Point by scalar") {
	Point p1(1, 1, 1);
	Point result = p1/5;
	REQUIRE(aboutEquals(result.x, 0.2));
	REQUIRE(aboutEquals(result.y, 0.2));
	REQUIRE(aboutEquals(result.z, 0.2));

	p1 = Point(-1, 1.5, 3);
	result = p1 / 1.5;
	REQUIRE(aboutEquals(result.x, -0.6666666));
	REQUIRE(aboutEquals(result.y, 1));
	REQUIRE(aboutEquals(result.z, 2));

	p1 = Point(1, 1, 3.5005);
	result = p1/1.1;
	REQUIRE(aboutEquals(result.z, 3.18227272));
}