#include "Form.hpp"
#include "Bureaucrat.hpp"

const int	Form::HIGHEST_GRADE = Bureaucrat::HIGHEST_GRADE;
const int	Form::LOWEST_GRADE = Bureaucrat::LOWEST_GRADE;

Form::Form():
	_name("(form)"),
	_signed(false),
	_gradeToSign(LOWEST_GRADE),
	_gradeToExecute(LOWEST_GRADE)
{}

Form::Form(const Form &src):
	_name(src._name),
	_signed(src._signed),
	_gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute)
{}

Form::Form(std::string name, bool sign,
		   int gradeToSign, int gradeToExecute):
	_name(name),
	_signed(sign),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return *this;
}

Form::~Form() {}

bool	Form::validateGrade(int grade)
{
	if (grade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	if (grade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	return (true);
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::isSigned() const
{
	return (this->_signed);
}

int		Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int		Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (isSigned())
	{
		std::cout << getName() << " is already signed." << std::endl;
		return ;
	}
	if (b.getGrade() > getGradeToSign())
	{
		std::cout << b.getName() << " couldn't sign "
				  << getName() << " because "
				  << b.getName() << "'s grade (" << b.getGrade() << ")"
				  << " is too low." << std::endl;
		return ;
	}
	_signed = true;
	std::cout << b.getName() << " signed "
			  << getName() << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << f.getName() << ": ";
	if (f.isSigned())
		os << "SIGNED. ";
	else
		os << "NOT SIGNED. ";
	os << "Needs grade " << f.getGradeToSign() << " to sign. ";
	os << "Needs grade " << f.getGradeToExecute() << " to execute.";
	return (os);
}

Form::GradeTooHighException::GradeTooHighException() {}
Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException& o){ (void)o; }
Form::GradeTooHighException& Form::GradeTooHighException::operator=(const GradeTooHighException& o){ (void)o; return *this; }
Form::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Form::GradeTooHighException::what() const throw() {
	return "ERROR: Form: grade too high.";
}

Form::GradeTooLowException::GradeTooLowException() {}
Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException& o){ (void)o; }
Form::GradeTooLowException& Form::GradeTooLowException::operator=(const GradeTooLowException& o){ (void)o; return *this; }
Form::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Form::GradeTooLowException::what() const throw() {
	return "ERROR: Form: grade too low.";
}
