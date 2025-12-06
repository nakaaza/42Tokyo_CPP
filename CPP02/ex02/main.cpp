#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a.toFloat() << std::endl;
	std::cout << ++a.toFloat() << std::endl;
	std::cout << a.toFloat() << std::endl;
	// std::cout << a++.toFloat() << std::endl;
	std::cout << a.toFloat() << std::endl;
	std::cout << b.toFloat() << std::endl;
	std::cout << Fixed::max( a, b ).toFloat() << std::endl;
	return 0;
}
