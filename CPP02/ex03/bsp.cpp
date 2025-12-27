#include "bsp.hpp"
#include <iostream>

static Fixed	cross_prod(Point const &a, Point const &b, Point const &c);

bool	bsp( Point const &a, Point const &b, Point const &c, Point const &point) {
	Fixed	abp = cross_prod(a, b, point);
	Fixed	bcp = cross_prod(b, c, point);
	Fixed	cap = cross_prod(c, a, point);

	if (abp > 0 && bcp > 0 && cap > 0)
		return (true);
	if (abp < 0 && bcp < 0 && cap < 0)
		return (true);
	return (false);
}

static Fixed	cross_prod(Point const &a, Point const &b, Point const &c) {
	return (
		(b.getX() - a.getX()) * (c.getY() - a.getY())
		- (b.getY() - a.getY()) * (c.getX() - a.getX())
	);
}
