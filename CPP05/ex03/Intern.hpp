#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <exception>
# include "AForm.hpp"

class Intern {

protected:


private:
	static AForm* makeShrubberyCreationForm(const std::string& target);
	static AForm* makeRobotomyRequestForm(const std::string& target);
	static AForm* makePresidentialPardonForm(const std::string& target);

public:
	Intern();
	Intern(const Intern &src);
	Intern &operator=(const Intern &rhs);
	~Intern();

	typedef AForm*	(*MakeFormF)(const std::string& target);
	AForm*	makeForm(const std::string name,
					 const std::string target);
};

std::string toUpperCamelCase(const std::string& input);

#endif // INTERN_HPP
