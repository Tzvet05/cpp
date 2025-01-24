#ifndef __POINT_H__
#define __POINT_H__

#include "Fixed.hpp"

class	Point
{
	public:
		Point(void);
		Point(const Point& point);
		Point& operator=(const Point&);
		~Point(void);

		Point(const float x, const float y);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
	private:
		const Fixed	_x;
		const Fixed	_y;
};

#endif
