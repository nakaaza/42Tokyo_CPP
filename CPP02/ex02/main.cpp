#include <iostream>
#include "Fixed.hpp"

static void	default_test( void );
static void	four_op_test( void ); 
static void	increment_test( void );
static void	comp_test( void );

int main( void ) {
	default_test();
	four_op_test();
	increment_test();
	comp_test();

	return 0;
}

static void	print_test_start(std::string test_name) {
	std::cout << "[" << test_name << "]" << std::string(20 - test_name.length(), '=') << std::endl;
}

static void	print_test_end( void ) {
	std::cout <<  std::string(22, '=') << std::endl;
}

static void	default_test( void ) {
	print_test_start("default test");

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	print_test_end();
}

static void	four_op_test( void ) {
	print_test_start("four op test");

	Fixed a = Fixed( 42 );
	Fixed b = Fixed( 4.2f );

	std::cout << "a = " <<  a << std::endl;
	std::cout << "b = " <<  b << std::endl;
	std::cout << "a + b = " <<  a + b << std::endl;
	std::cout << "a - b = " <<  a - b << std::endl;
	std::cout << "a * b = " <<  a * b << std::endl;
	std::cout << "a / b = " <<  a / b << std::endl;

	print_test_end();
}

static void	increment_test( void ) {
	print_test_start("increment test");

	Fixed a = Fixed( 0.0f );

	std::cout << "a = " <<  a << std::endl;
	std::cout << "++a: " << a << " -> " << ++a << " -> " << a << std::endl;
	std::cout << "a++: " << a << " -> " << a++ << " -> " << a << std::endl;
	std::cout << "--a: " << a << " -> " << --a << " -> " << a << std::endl;
	std::cout << "a--: " << a << " -> " << a-- << " -> " << a << std::endl;
	std::cout << "a = " <<  a << std::endl;

	print_test_end();
}

static void	unit_comp_test(const Fixed a,  const Fixed b) {
	std::cout << "a = " <<  a << std::endl;
	std::cout << "b = " <<  b << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min(a, b) = " << Fixed::min( a, b ) << std::endl;
	std::cout << std::endl;
}

static void	comp_test( void ) {
	print_test_start("comp test");

	unit_comp_test(Fixed(4.0f), Fixed(2));
	unit_comp_test(Fixed(2.0f), Fixed(4));
	unit_comp_test(Fixed(42.0f), Fixed(42));

	print_test_end();
}
