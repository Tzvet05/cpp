#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	denominator, barA, barB, barC;

	denominator = (b.getY() - c.getY()) * (a.getX() - c.getX())
		+ (c.getX() - b.getX()) * (a.getY() - c.getY());
	barA = ((b.getY() - c.getY()) * (point.getX() - c.getX())
		+ (c.getX() - b.getX()) * (point.getY() - c.getY())) / denominator;
	barB = ((c.getY() - a.getY()) * (point.getX() - c.getX())
		+ (a.getX() - c.getX()) * (point.getY() - c.getY())) / denominator;
	barC = Fixed(1.0f) - barA - barB;
	return (barA > 0.0f && barA < 1.0f
		&& barB > 0.0f && barB < 1.0f
		&& barC > 0.0f && barC < 1.0f);
}
