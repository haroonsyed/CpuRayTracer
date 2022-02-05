#pragma once
#include <catch2/catch.hpp>
#include <iostream>
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
	v.normalize();
	REQUIRE(aboutEquals(v.xCom, 4./5));
	REQUIRE(aboutEquals(v.yCom, 3./5));
	REQUIRE(aboutEquals(v.zCom, 0));


	//Check from two non-origin points
	p1 = Point(6, 1, sqrt(8));
	p2 = Point(4, 3, 0);
	v = Vector(p1, p2);
	v.normalize();
	REQUIRE(aboutEquals(v.xCom, -2. / 4));
	REQUIRE(aboutEquals(v.yCom, 2. / 4));
	REQUIRE(aboutEquals(v.zCom, -sqrt(8) / 4));
}

TEST_CASE("Creating a vector from components") {
	Vector v(1,0,0);
	REQUIRE(aboutEquals(v.xCom, 1));
	REQUIRE(aboutEquals(v.yCom, 0));
	REQUIRE(aboutEquals(v.zCom, 0));

	//Check normalization works
	v = Vector(0, 4, 6);
	v.normalize();
	REQUIRE(aboutEquals(v.xCom, 0));
	REQUIRE(aboutEquals(v.yCom, 4./ 7.21110255));
	REQUIRE(aboutEquals(v.zCom, 6./ 7.21110255));
}

TEST_CASE("Adding vectors") {
	Vector v1(0, 0, 1);
	Vector v2(1, 0, 0);
	Vector result = v1 + v2;
	Vector correct = Vector(1,0,1);
	REQUIRE((result == correct));

	v1 = Vector(1.235, 258.25, 5437.3);
	v2 = Vector(-125.235, 53.25, -537.5);
	result = v1 + v2;
	correct = Vector(1.235-125.235,258.25+53.25,5437.3-537.5);
	REQUIRE((result==correct));
}

TEST_CASE("Subtracting vectors") {
	Vector v1(0, 0, 1);
	Vector v2(1, 0, 0);
	Vector result = v1 - v2;
	Vector correct = Vector(-1, 0, 1);
	REQUIRE((result == correct));

	v1 = Vector(1.235, 258.25, 5437.3);
	v2 = Vector(-125.235, 53.25, -537.5);
	result = v1 - v2;
	correct = Vector(1.235 + 125.235, 258.25 - 53.25, 5437.3 + 537.5);
	REQUIRE((result == correct));
}

TEST_CASE("Multiply vector by scaler") {
	Vector v1(0, 0, 1);
	Vector result = v1*50;
	Vector correct = Vector(0, 0, 50);
	REQUIRE((result == correct));

	v1 = Vector(2,4.363,5.213);
	result = v1 * 325.23;
	correct = Vector(2* 325.23, 4.363* 325.23, 5.213* 325.23);
	REQUIRE((result == correct));

	//Reverse operator order
	v1 = Vector(2, 4.363, 5.213);
	result = 325.23*v1;
	correct = Vector(2 * 325.23, 4.363 * 325.23, 5.213 * 325.23);
	REQUIRE((result == correct));
}

TEST_CASE("Divide vector by scaler") {
	Vector v1(0, 0, 1);
	Vector result = v1 / 50;
	Vector correct = Vector(0, 0, 1./50);
	REQUIRE((result == correct));

	v1 = Vector(2, 4.363, 5.213);
	result = v1 / 325.23;
	correct = Vector(2. / 325.23, 4.363 / 325.23, 5.213 / 325.23);
	REQUIRE((result == correct));
}

TEST_CASE("Cross product of two vectors") {
	Vector v1(5.325,235.5,325);
	Vector v2(234, 259, 19.2);
	Vector result = v1.cross(v2);
	Vector correct(-79653.4, 75947.76, -53727.825);
	REQUIRE((result==correct));
}
