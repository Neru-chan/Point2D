#pragma once
#define _USE_MATH_DEFINES

#include <cmath>
#include <string>
#include <format>

class PolarCoordinate
{
public:
	PolarCoordinate(const float& r, const float& a) :
		r(r),
		a(a) {}

	std::string to_string() {
		return std::format("({}, {})", r, a);
	}

	// radius
	float r;

	//angle, radians
	float a;
};

class Point2D {
public:
	Point2D();
	Point2D(const float&, const float&);
	~Point2D();

	std::string to_string();

	void move_x(const float&);
	void move_y(const float&);
	float distance(const Point2D&);
	float distance_to_zero();
	PolarCoordinate to_polar();

private:
	float x;
	float y;
};