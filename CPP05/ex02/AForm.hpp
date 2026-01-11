#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>

class Bureaucrat;

class AForm {

private:
	const static int	HIGHEST_GRADE;
	const static int	LOWEST_GRADE;

	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;

	void				_setGradeToSign(int grade);
	void				_setGradeToExecute(int grade);
	static bool			validateGrade(int grade);

public:
	AForm();
	AForm(const AForm &src);
	AForm(std::string name,
		 bool sign = false,
		 int gradeToSign = HIGHEST_GRADE,
		 int gradeToExecute = HIGHEST_GRADE
		);
	AForm &operator=(const AForm &rhs);
	~AForm();

	std::string	getName() const;
	bool		isSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void		beSigned(Bureaucrat &b);

	class GradeTooHighException : public std::exception {
		public:
			GradeTooHighException();
			GradeTooHighException(const GradeTooHighException& other);
			GradeTooHighException& operator=(const GradeTooHighException& other);
			virtual ~GradeTooHighException() throw();
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			GradeTooLowException();
			GradeTooLowException(const GradeTooLowException& other);
			GradeTooLowException& operator=(const GradeTooLowException& other);
			virtual ~GradeTooLowException() throw();
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif // AForm_HPP
