#include "AForm.hpp"
#include "Bureaucrat.hpp"

const int	AForm::HIGHEST_GRADE = Bureaucrat::HIGHEST_GRADE;
const int	AForm::LOWEST_GRADE = Bureaucrat::LOWEST_GRADE;

AForm::AForm():
	_name("(AForm)"),
	_gradeToSign(LOWEST_GRADE),
	_gradeToExecute(LOWEST_GRADE),
	_signed(false)
{}

AForm::AForm(const AForm &src):
	_name(src._name),
	_gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute),
	_signed(src._signed)
{}

AForm::AForm(std::string name,
			 int gradeToSign,
			 int gradeToExecute,
			 bool sign):
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(sign)
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

void	AForm::beSigned(Bureaucrat const &signer)
{
	if (isSigned())
		throw AlreadySignedException();
	if (signer.getGrade() > getGradeToSign())
		throw GradeTooLowToSignException();
	_signed = true;
	return ;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowToExecuteException();
	doExecute(executor);
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

const char* AForm::GradeTooHighException::what() const throw() {
	return "ERROR: AForm: grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "ERROR: AForm: grade too low.";
}

const char* AForm::GradeTooLowToSignException::what() const throw() {
	return "ERROR: AForm: grade too low to sign.";
}

const char* AForm::GradeTooLowToExecuteException::what() const throw() {
	return "ERROR: AForm: grade too low to sign.";
}

const char* AForm::AlreadySignedException::what() const throw() {
	return "ERROR: AForm: already signed";
}

const char* AForm::NotSignedException::what() const throw() {
	return "ERROR: AForm: not signed when execution";
}
