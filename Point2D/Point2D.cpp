#include "Point2D.h"

float Point2D::distance(const Point2D& other) const
{
	return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
}

float Point2D::distance_to_zero() const
{
	return distance(Point2D(0, 0));
}

PolarCoordinate Point2D::to_polar() const
{
	float radius = sqrt(x*x + y*y);
	float radian = 0;
	if (radius == 0) return PolarCoordinate(0, 0);

	if (x > 0)
		radian = atan(y / x);

	if (x < 0 && y >= 0)
		radian = atan(y / x) + M_PI;

	if (x < 0 && y < 0)
		radian = atan(y / x) - M_PI;

	if (x == 0 && y > 0)
		radian = M_PI_2;
	
	if (x == 0 && y < 0)
		radian = -M_PI_2;

	return PolarCoordinate(radius, radian);
}

float Point2D::get_x() const
{
	return x;
}

float Point2D::get_y() const
{
	return y;
}

Point2D::Point2D() :
	x(0),
	y(0) {}

Point2D::Point2D(const float& x, const float& y) :
	x(x),
	y(y) {}

Point2D::~Point2D()
{

}

std::string Point2D::to_string() const
{
	return std::format("({}, {})", x, y);
}

void Point2D::move_x(const float& x)
{
	this->x += x;
}

void Point2D::move_y(const float& x)
{
	this->y += y;
}

