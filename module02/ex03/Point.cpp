#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void): _x(0), _y(0)
{
}

Point::Point(const Point& point): _x(point._x), _y(point._y)
{
}

Point& Point::operator=(const Point& rhs)
{
	(void)rhs;
	return (*this);
}

Point::~Point(void)
{
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
}

Fixed	Point::getX(void) const
{
	return (_x);
}

Fixed	Point::getY(void) const
{
	return (_y);
}
