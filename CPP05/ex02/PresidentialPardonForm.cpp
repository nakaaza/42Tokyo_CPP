#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src):
	AForm(src),
	_target(src._target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::doExecute(Bureaucrat const &executor) const
{
	std::cout << "PresidentPardonForm::doExecute() by" << executor.getName() << " with target = " << _target << std::endl;
	return ;
}
