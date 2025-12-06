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
	// TODO: check float overflow
	float	scaled = ini_val * scale;

	if (scaled == NAN)
		throw std::overflow_error("Fixed: NaN is out of range");
	if (scaled == INFINITY || scaled == -INFINITY)
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

bool	Fixed::operator>(const Fixed &rhs) {
	return (this->val > rhs.val);
}

bool	Fixed::operator<(const Fixed &rhs) {
	return (this->val < rhs.val);
}

bool	Fixed::operator>=(const Fixed &rhs) {
	return (this->val >= rhs.val);
}

bool	Fixed::operator<=(const Fixed &rhs) {
	return (this->val <= rhs.val);
}

bool	Fixed::operator==(const Fixed &rhs) {
	return (this->val == rhs.val);
}

bool	Fixed::operator!=(const Fixed &rhs) {
	return (this->val != rhs.val);
}

Fixed	Fixed::operator+(const Fixed &rhs) {
	return (this->val + rhs.val);
}

Fixed	Fixed::operator-(const Fixed &rhs) {
	return (this->val - rhs.val);
}

Fixed	Fixed::operator*(const Fixed &rhs) {
	return (this->val * rhs.val);
}

Fixed	Fixed::operator/(const Fixed &rhs) {
	// TODO: 0 division?
	return (this->val / rhs.val);
}

Fixed	&Fixed::operator++() {
	Fixed	&res = *this;
	this->val += FIXED_EPS;
	return (res);
}

// Fixed	&operator--();
// Fixed	&operator();
// Fixed	&operator();

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	// TODO: include equal?
	if (f1 > f2)
		return (f2);
	return (f1);
}

Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	// TODO: include equal?
	if (f1 > f2)
		return (f2);
	return (f1);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	// TODO: include equal?
	if (f1 < f2)
		return (f2);
	return (f1);
}

Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	// TODO: include equal?
	if (f1 < f2)
		return (f2);
	return (f1);
}

// std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
// {
// 	os << fixed.toFloat();
// 	return (os);
// }
