#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException& o){ (void)o; }
Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException& o){ (void)o; return *this; }
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "ERROR: Bureaucrat: grade too high.";
}
