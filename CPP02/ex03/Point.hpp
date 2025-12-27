#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

private:
	const Fixed	x;
	const Fixed	y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point &src);
	Point &operator=(const Point &rhs);
	~Point();

	Fixed	getX() const;
	Fixed	getY() const;
};

std::ostream &operator<<(std::ostream &os, const Point &point);

#endif // POINT_HPP
