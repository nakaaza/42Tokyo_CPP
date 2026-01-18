#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat vPresident("VICE_PRESIDENT", 5);

	std::cout << vPresident << std::endl;

	Intern intern;
	AForm*	forms[] = {
		intern.makeForm("shrubbery creation", "shshsh"),
		intern.makeForm("shrubbery-creation", "shshsh2"),
		intern.makeForm("shrubberyCreation", "shshsh3"),
		intern.makeForm("robotomy-request", "grrrrr"),
		intern.makeForm("presidential pardon", "prpprp")
	};

	for (int i = 0; i < 5; i++)
		vPresident.signForm(*forms[i]);

	for (int i = 0; i < 5; i++)
		vPresident.executeForm(*forms[i]);

	for (int i = 0; i < 5; i++)
		delete forms[i];
	
	return (0);
}
