#include <iostream>
#include <cstdlib>
#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

// TEST CASES ================================
// P is inside ABC.
// ./bsp 0 0 5 0 2.5 5 2.5 1
// ./bsp 0 1 0.866 -0.5 -0.866 -0.5 0 0
//
// P is NOT inside ABC.
// ./bsp 0 0 5 0 2.5 5 2.5 10
// ./bsp 0 0 5 0 2.5 5 2.5 0 (P is on the edge)
// ===========================================

int main(int argc, char **argv) {
	if (argc != 9)
	{
		std::cout << "Invalid arguments:" << std::endl;
		std::cout << "./bsp [x of A] [y of A] [x of B] [y of B] [x of C] [y of C] [x of P] [y of P]" << std::endl;
		std::cout << "All x and y are float" << std::endl;
	}
	Point	a(static_cast<float>(std::atof(argv[1])),
			  static_cast<float>(std::atof(argv[2])));
	Point	b(static_cast<float>(std::atof(argv[3])),
			  static_cast<float>(std::atof(argv[4])));
	Point	c(static_cast<float>(std::atof(argv[5])),
			  static_cast<float>(std::atof(argv[6])));
	Point	p(static_cast<float>(std::atof(argv[7])),
			  static_cast<float>(std::atof(argv[8])));
	
	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
	std::cout << "C: " << c << std::endl;
	std::cout << "P: " << p << std::endl;

	bool	res = bsp(a, b, c, p);
	std::cout << "BSP result: P is ";
	if (!res)
		std::cout << "NOT ";
	std::cout << "inside ABC." << std::endl;
	return 0;
}
