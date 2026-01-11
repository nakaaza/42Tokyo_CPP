#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException& o){ (void)o; }
Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException& o){ (void)o; return *this; }
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "ERROR: Bureaucrat: grade too high.";
}

Form::GradeTooHighException::GradeTooHighException() {}
Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException& o){ (void)o; }
Form::GradeTooHighException& Form::GradeTooHighException::operator=(const GradeTooHighException& o){ (void)o; return *this; }
Form::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Form::GradeTooHighException::what() const throw() {
	return "ERROR: Form: grade too high.";
}
