#include "Fixed.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>

const int	Fixed::frac_bits = FRAC_BITS;

Fixed::Fixed(): val(0) {
	std::cout << "Default constructor called" << std::endl;
	return ; 
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int ini_val) {
	std::cout << "Int constructor called" << std::endl;
	if (ini_val < FIXED_MIN || FIXED_MAX < ini_val)
		throw std::overflow_error("Fixed: given int is out of Fixed range");
	this->val = ini_val << Fixed::frac_bits;
	return ;
}

Fixed::Fixed(const float ini_val) {
	std::cout << "Float constructor called" << std::endl;
	float	scale = static_cast<float>(1 << Fixed::frac_bits);
	float	scaled = ini_val * scale;

	if (scaled != scaled)
		throw std::overflow_error("Fixed: NaN is out of range");
	if (scaled == std::numeric_limits<float>::infinity()
		|| scaled == -std::numeric_limits<float>::infinity())
		throw std::overflow_error("Fixed: INFINITY is out of range");
	if (scaled < static_cast<float>(FIXED_MIN)
		|| static_cast<float>(FIXED_MAX) < scaled)
		throw std::overflow_error("Fixed: given float is out of Fixed range");
	if (scaled >= 0.0f)
		this->val = static_cast<int>(scaled + 0.5f);
	else
		this->val = static_cast<int>(scaled - 0.5f);
	return ;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->setRawBits(rhs.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->val);
}

void	Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->val = raw;
	return ;
}

float	Fixed::toFloat(void) const {
	float	scale = static_cast<float>(1 << Fixed::frac_bits);
	return (static_cast<float>(this->val) / scale);
}

int		Fixed::toInt(void) const {
	return (this->val >> Fixed::frac_bits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
