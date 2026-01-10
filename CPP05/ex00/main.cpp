#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== Default constructor test" << std::endl;
	try {
		Bureaucrat a;
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade(); // -> throws Bureaucrat::GradeTooLowException
		std::cout << a << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "=== Constructor with name and grade test" << std::endl;
	try {
		Bureaucrat b("Bob Dylan", 2);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade(); // -> throws Bureaucrat::GradeTooHighException
		std::cout << b << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
