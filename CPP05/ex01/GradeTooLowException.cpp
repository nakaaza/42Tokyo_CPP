#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::GradeTooLowException::GradeTooLowException() {}
Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException& o){ (void)o; }
Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException& o){ (void)o; return *this; }
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "ERROR: Bureaucrat: grade too low.";
}

Form::GradeTooLowException::GradeTooLowException() {}
Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException& o){ (void)o; }
Form::GradeTooLowException& Form::GradeTooLowException::operator=(const GradeTooLowException& o){ (void)o; return *this; }
Form::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Form::GradeTooLowException::what() const throw() {
	return "ERROR: Form: grade too low.";
}
