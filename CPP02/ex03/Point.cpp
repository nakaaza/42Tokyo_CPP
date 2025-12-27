#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

Point::Point(): x(Fixed(0)), y(Fixed(0)) {
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
	return ; 
}

Point::Point(const float x, const float y): x(Fixed(x)), y(Fixed(y)) {
	if (DEBUG)
		std::cout << "Constructor with params called" << std::endl;
	return ; 
}

Point::Point(const Point &src): x(src.x), y(src.y) {
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Point &Point::operator=(const Point &rhs) {
	if (DEBUG)
		std::cout << "Copy assignment operator called" << std::endl;
	(void) rhs;
	return *this;
}

Point::~Point() {
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed	Point::getX() const {
	return (this->x);
}

Fixed	Point::getY() const {
	return (this->y);
}

std::ostream &operator<<(std::ostream &os, const Point &point)
{
	os << "Point(" << point.getX() << ", " << point.getY() << ")";
	return (os);
}
