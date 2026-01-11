#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat p("PRESIDENT", Bureaucrat::HIGHEST_GRADE);
	Bureaucrat b("BOSS", 10);
	Bureaucrat r("ROOKIE", Bureaucrat::LOWEST_GRADE);

	std::cout << p << std::endl;
	std::cout << b << std::endl;
	std::cout << r << std::endl;
	
	std::cout << "=== Default constructor test" << std::endl;
	Form f1_1;
	Form f1_2;
	Form f1_3;
	std::cout << f1_1 << std::endl;
	p.signForm(f1_1);
	b.signForm(f1_2);
	r.signForm(f1_3);
	// -> Every form would be signed.

	p.signForm(f1_3); // -> already signed
	
	std::cout << "=== Constructor with valid params test" << std::endl;
	Form f2_1("FORM", false, 5, 5);
	Form f2_2 = f2_1;
	Form f2_3 = f2_1;
	std::cout << f2_1 << std::endl;
	p.signForm(f2_1);
	b.signForm(f2_2);
	r.signForm(f2_3); // -> Can't be signed
	p.signForm(f2_3); // -> signed
	b.signForm(f2_3); // -> already signed

	std::cout << "=== Constructor with invalid params test" << std::endl;
	try {
		Form f3_1("FORM", false, 0, 5);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form f3_1("FORM", false, 5, 151);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
