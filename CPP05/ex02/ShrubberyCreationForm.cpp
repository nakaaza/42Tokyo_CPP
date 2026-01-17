#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src):
	AForm(src),
	_target(src._target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::doExecute(Bureaucrat const &executor) const
{
	std::cout << "ShrubberyCreationForm::doExecute() by" << executor.getName() << " with target = " << _target << std::endl;
	return ;
}
