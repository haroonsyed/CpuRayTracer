#pragma once
#include <catch2/catch.hpp>
#include <iostream>
#include "../math/mathutil.h"
#include "../math/vector.h"
#include "../math/Vector.h"

TEST_CASE("Creating a vector from two Vectors") {
	Vector p1(0, 0, 0);
	Vector p2(1, 0, 0);
	Vector v(p1, p2);
	REQUIRE(aboutEquals(v.xCom,1));
	REQUIRE(aboutEquals(v.yCom, 0));
	REQUIRE(aboutEquals(v.zCom, 0));

	//Check vector is normalized
	p1 = Vector(0,0,0);
	p2 = Vector(4,3,0);
	v = Vector(p1, p2);
	v.normalize();
	REQUIRE(aboutEquals(v.xCom, 4./5));
	REQUIRE(aboutEquals(v.yCom, 3./5));
	REQUIRE(aboutEquals(v.zCom, 0));


	//Check from two non-origin Vectors
	p1 = Vector(6, 1, sqrt(8));
	p2 = Vector(4, 3, 0);
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
	//Positive numbers
	Vector v1(5.325,235.5,325);
	Vector v2(234, 259, 19.2);
	Vector result = v1.cross(v2);
	Vector correct(-79653.4, 75947.76, -53727.825);
	REQUIRE((result==correct));

	//With negative numbers
	v1 = Vector(-2358.1254, -252.1, 2543);
	v2 = Vector(1258.2122, 940.22224, -2042.2);
	result = v1.cross(v2);
	correct = Vector(-1876146.53632, -1616130.06728, -1899966.6501688962);
	REQUIRE((result == correct));
}

TEST_CASE("Dot product of two vectors") {
	//Positive numbers
	Vector v1(5.325, 235.5, 325);
	Vector v2(234, 259, 19.2);
	REQUIRE(aboutEquals(v1.dot(v2),68480.55));

	//With negative numbers
	v1 = Vector(-2358.1254, -252.1, 2543);
	v2 = Vector(1258.2122, 940.22224, -2042.2);
	REQUIRE(aboutEquals(v1.dot(v2),-8397366.7741139));
}

TEST_CASE("Magnitude of a vector") {
	Vector v(0, 0, 0);
	REQUIRE(aboutEquals(v.magnitude(),0));

	v = Vector(3,4,0);
	REQUIRE(aboutEquals(v.magnitude(), 5));

	v = Vector(223.2362,23642.634,1523.526);
	REQUIRE(aboutEquals(v.magnitude(), 23692.722687180));

	//With negative numbers
	v = Vector(-1.000262, -253.235, 1248.33);
	REQUIRE(aboutEquals(v.magnitude(), 1273.75694488));
}

TEST_CASE("Check getPerpendicular() is valid") {
	Vector v(1, 0, 0);
	Vector perp = v.getPerpendicular();
	REQUIRE(aboutEquals(v.dot(perp), 0));
	REQUIRE((v != perp));

	v = Vector(-1523,2643, 373);
	perp = v.getPerpendicular();
	v.normalize();
	REQUIRE(aboutEquals(v.dot(perp), 0));
	REQUIRE((v != perp));
}
