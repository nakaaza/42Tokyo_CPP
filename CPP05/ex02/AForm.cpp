#include "AForm.hpp"
#include "Bureaucrat.hpp"

const int	AForm::HIGHEST_GRADE = Bureaucrat::HIGHEST_GRADE;
const int	AForm::LOWEST_GRADE = Bureaucrat::LOWEST_GRADE;

AForm::AForm():
	_name("(AForm)"),
	_signed(false),
	_gradeToSign(LOWEST_GRADE),
	_gradeToExecute(LOWEST_GRADE)
{}

AForm::AForm(const AForm &src):
	_name(src._name),
	_signed(src._signed),
	_gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute)
{}

AForm::AForm(std::string name, bool sign,
		   int gradeToSign, int gradeToExecute):
	_name(name),
	_signed(sign),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return *this;
}

AForm::~AForm() {}

bool	AForm::validateGrade(int grade)
{
	if (grade > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
	if (grade < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	return (true);
}

std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::isSigned() const
{
	return (this->_signed);
}

int		AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int		AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat &b)
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

std::ostream &operator<<(std::ostream &os, const AForm &f)
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

AForm::GradeTooHighException::GradeTooHighException() {}
AForm::GradeTooHighException::GradeTooHighException(const GradeTooHighException& o){ (void)o; }
AForm::GradeTooHighException& AForm::GradeTooHighException::operator=(const GradeTooHighException& o){ (void)o; return *this; }
AForm::GradeTooHighException::~GradeTooHighException() throw() {}
const char* AForm::GradeTooHighException::what() const throw() {
	return "ERROR: AForm: grade too high.";
}

AForm::GradeTooLowException::GradeTooLowException() {}
AForm::GradeTooLowException::GradeTooLowException(const GradeTooLowException& o){ (void)o; }
AForm::GradeTooLowException& AForm::GradeTooLowException::operator=(const GradeTooLowException& o){ (void)o; return *this; }
AForm::GradeTooLowException::~GradeTooLowException() throw() {}
const char* AForm::GradeTooLowException::what() const throw() {
	return "ERROR: AForm: grade too low.";
}
