#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src):
	AForm(src),
	_target(src._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::doExecute(Bureaucrat const &executor) const
{
	std::cout << "RobtomyRequestForm::doExecute() by" << executor.getName() << " with target = " << _target << std::endl;
	return ;
}
