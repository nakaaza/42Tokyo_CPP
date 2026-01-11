#include "Bureaucrat.hpp"

Bureaucrat::GradeTooLowException::GradeTooLowException() {}
Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException& o){ (void)o; }
Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException& o){ (void)o; return *this; }
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "ERROR: Bureaucrat: grade too low.";
}
