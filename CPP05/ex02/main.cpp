#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat rookie("ROOKIE", Bureaucrat::LOWEST_GRADE);
	Bureaucrat staff("STAFF", 140);
	Bureaucrat manager("MANAGER", 100);
	Bureaucrat director("DIRECTOR", 50);
	Bureaucrat executive("EXECUTIVE", 30);
	Bureaucrat chief("CHIEF", 10);
	Bureaucrat vPresident("VICE_PRESIDENT", 5);

	std::cout << rookie << std::endl;
	std::cout << staff << std::endl;
	std::cout << manager << std::endl;
	std::cout << director << std::endl;
	std::cout << executive << std::endl;
	std::cout << chief << std::endl;
	std::cout << vPresident << std::endl;
	std::cout << std::endl;

	std::cout << "=== ShrubberyCreationForm test" << std::endl;
	ShrubberyCreationForm s1("shrubbery");
	std::cout << s1 << std::endl;
	manager.executeForm(s1);	// -> manager can't execute because s1 is not signed
	rookie.signForm(s1);		// -> rookie can't sign s1 because the grade too low.
	staff.signForm(s1);			// -> staff can sign s1
	staff.executeForm(s1);		// -> staff can't execute s1 because the grade too low
	manager.signForm(s1);		// -> s1 already signed
	manager.executeForm(s1);	// -> manager can execute s1
	std::cout << "===" << std::endl << std::endl;

	std::cout << "=== RobotomyRequestForm test" << std::endl;
	RobotomyRequestForm s2("robotomy");
	std::cout << s2 << std::endl;
	executive.executeForm(s2);	// -> executive can't execute because s2 is not signed
	manager.signForm(s2);		// -> manager can't sign s2 because the grade too low.
	director.signForm(s2);		// -> director can sign s2
	director.executeForm(s2);	// -> director can't execute s2 because the grade too low
	executive.signForm(s2);		// -> s2 already signed
	executive.executeForm(s2);	// -> executive can execute s2
	std::cout << "===" << std::endl << std::endl;

	std::cout << "=== PresidentPardonForm test" << std::endl;
	PresidentialPardonForm s3("president");
	std::cout << s3 << std::endl;
	vPresident.executeForm(s3);	// -> vPresident can't execute because s3 is not signed
	executive.signForm(s3);		// -> executive can't sign s3 because the grade too low.
	chief.signForm(s3);			// -> chief can sign s3
	chief.executeForm(s3);		// -> chief can't execute s3 because the grade too low
	vPresident.signForm(s3);	// -> s3 already signed
	vPresident.executeForm(s3);	// -> vPresident can execute s3
	std::cout << "===" << std::endl << std::endl;

	return (0);
}
