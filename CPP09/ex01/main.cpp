#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Argument Error: 1 argument representing Reverse Polish Notation required." << std::endl
				  << "./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
		return 1;
	}
	std::string formula = argv[1];
	try {
		long res = RPN::evaluate(formula);
		std::cout << res << std::endl;
		return 0;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
