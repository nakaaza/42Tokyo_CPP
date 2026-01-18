#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &src) { (void) src; }

Intern &Intern::operator=(const Intern &rhs) {
	if (this != &rhs) 
		*this = rhs;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string name,
						 const std::string target)
{
	static const std::string	forms[3] = { "ShrubberyCreation", "RobotomyRequest", "PresidentialPardon" };

	static const MakeFormF makers[] = {
		&makeShrubberyCreationForm,
		&makeRobotomyRequestForm,
		&makePresidentialPardonForm
	};

	AForm* res = NULL;

	std::string	formattedName = toUpperCamelCase(name);
	int	i = -1;
	while (++i < 3)
	{
		if (forms[i] == formattedName)
			res = (makers[i])(target);
	}
	
	if (res) {
		std::cout << "Intern creates " << formattedName << "Form" << std::endl;
		return (res);
	} else { 
		std::cout << "Intern couldn't make form because "
				  << name << " doesn't match any of the Form candidates."
				  << std::endl;
		return (NULL);
	}
}

std::string toUpperCamelCase(const std::string& input)
{
	std::string result;
	bool newWord = true;

	for (std::string::size_type i = 0; i < input.size(); ++i) {
		unsigned char c = static_cast<unsigned char>(input[i]);

		if (std::isalnum(c)) {
			if (!newWord && std::isupper(c))
				newWord = true;
			if (newWord) {
				result += static_cast<char>(std::toupper(c));
				newWord = false;
			} else
				result += static_cast<char>(std::tolower(c));
		} else
			newWord = true;
	}
	return (result);
}
