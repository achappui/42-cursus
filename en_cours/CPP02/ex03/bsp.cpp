#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point p)
{
	Fixed	abCrossProduct;
	Fixed	bcCrossProduct;
	Fixed	caCrossProduct;

	abCrossProduct = (
	(b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX()));
	bcCrossProduct = (
	(c.getX() - b.getX()) * (p.getY() - b.getY()) - (c.getY() - b.getY()) * (p.getX() - b.getX()));
	caCrossProduct = (
	(a.getX() - c.getX()) * (p.getY() - c.getY()) - (a.getY() - c.getY()) * (p.getX() - c.getX()));
	if ((abCrossProduct < 0 && bcCrossProduct < 0 && caCrossProduct < 0) || \
		(abCrossProduct > 0 && bcCrossProduct > 0 && caCrossProduct > 0))
		return (1);
	return (0);
}