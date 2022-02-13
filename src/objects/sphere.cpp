#include "sphere.h"

Sphere::Sphere(Vector& p, double r, Material& mat) :SceneObj(p, mat) {
	radius = r;
}
Intersection Sphere::doesIntersect(Ray& ray) {
	Vector d = ray.vector;
	Vector e = ray.origin;
	Vector c = position;
	double r = radius;
	double B = 2 * d.dot(e - c);
	double A = d.dot(d);
	double C = (e - c).dot(e - c) - r * r;
	double discriminant = B * B - 4 * A * C;
	if (discriminant <= 0) {
		return Intersection();
	}
	else {
		double discRoot = std::sqrt(discriminant);
		double t = std::min((-1 * B + discRoot) / (2 * A), (-1 * B - discRoot) / (2 * A));
		if (t < 0) {
			return Intersection();
		}
		Vector p = ray.origin + t * ray.vector;
		Vector n = (p - c) / r;
		return Intersection(t, p, n, mat);
	}
}
void Sphere::print() {
	std::cout << "Radius" << radius << std::endl;
	std::cout << "Position\n";
	position.print();
}