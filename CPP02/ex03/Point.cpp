#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

Point::Point(): x(Fixed(0)), y(Fixed(0)) {
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
	return ; 
}

Point::Point(const Fixed x, const Fixed y): x(x), y(y) {
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
	return *this;
}

Point::~Point() {
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
	return ;
}

void	Point::setX(const Fixed x) {
	this->x = x;
}

void	Point::setY(const Fixed y) {

}
