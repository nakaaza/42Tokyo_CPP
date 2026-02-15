#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void basic_test()
{
	std::cout << "[Basic test] ========================" << std::endl;
	Span sp = Span(5);
	std::cout << "Created Span with capacity of 5 elements" << std::endl;
	try {
		std::cout << "Trying to execute shortestSpan() with 0 elements" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << "-> SUCCESS!" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "Trying to execute addNumber() with 0 elements" << std::endl;
		sp.addNumber(6);
		std::cout << "-> SUCCESS!" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "Trying to execute longestSpan() with 1 element" << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "-> SUCCESS!" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Added 5 elements to Span" << std::endl;
		std::cout << "-> SUCCESS!" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() <<std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "Trying to execute shortestSpan() with 5 elements" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << "-> SUCCESS!" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "Trying to execute longestSpan() with 5 elements" << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "-> SUCCESS!" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "Trying to execute addNumber() with 5 elements" << std::endl;
		sp.addNumber(42);
		std::cout << "-> SUCCESS!" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return;
}

void	big_test()
{
	std::cout << "[Big test] ========================" << std::endl;
	std::srand(std::time(NULL));

	std::vector<int>::size_type size = 42000;
	std::vector<int> v;
	v.reserve(size);

	for (std::size_t i = 0; i < size; ++i)
		v.push_back(rand());

	Span	small = Span(size / 2);
	try {
		std::cout << "Trying to excecute add " << size << " elements to small Span with capacity of " << size / 2 << std::endl;
		small.addNumbers(v.begin(), v.end());
		std::cout << "-> SUCCESS!" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	Span	big = Span(size);
	try {
		std::cout << "Trying to excecute add " << size << " elements to big Span with capacity of " << size << std::endl;
		big.addNumbers(v.begin(), v.end());
		std::cout << "-> SUCCESS!" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "Trying to execute shortestSpan() with " << size << " elements" << std::endl;
		std::cout << big.shortestSpan() << std::endl;
		std::cout << "-> SUCCESS!" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "Trying to execute longestSpan() with " << size << " elements" << std::endl;
		std::cout << big.longestSpan() << std::endl;
		std::cout << "-> SUCCESS!" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}


int	main(void)
{
	basic_test();
	std::cout << std::endl;
	big_test();
}
