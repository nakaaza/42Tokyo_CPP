#include "Bureaucrat.hpp"

const int	Bureaucrat::HIGHEST_GRADE = 1;
const int	Bureaucrat::LOWEST_GRADE = 150;

Bureaucrat::Bureaucrat():
	_name("(bureaucrat)"),
	_grade(LOWEST_GRADE)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade):
	_name(name)
{
	_setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src):
	_name(src._name),
	_grade(src._grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs)
		this->_setGrade(rhs.getGrade());
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

bool	Bureaucrat::validateGrade(int grade) {
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	return (true);
}

void	Bureaucrat::_setGrade(int grade) {
	if (validateGrade(grade))
		this->_grade = grade;
}

std::string	Bureaucrat::getName() const {
	return (this->_name);
}

int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::incrementGrade() {
	if (validateGrade(_grade - 1))
		_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (validateGrade(_grade + 1))
		_grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException& o){ (void)o; }
Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException& o){ (void)o; return *this; }
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "ERROR: Bureaucrat: grade too high.";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}
Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException& o){ (void)o; }
Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException& o){ (void)o; return *this; }
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "ERROR: Bureaucrat: grade too low.";
}
