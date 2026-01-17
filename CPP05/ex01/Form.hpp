#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form {

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
	Form();
	Form(const Form &src);
	Form(std::string name,
		 bool sign = false,
		 int gradeToSign = HIGHEST_GRADE,
		 int gradeToExecute = HIGHEST_GRADE
		);
	Form &operator=(const Form &rhs);
	~Form();

	std::string	getName() const;
	bool		isSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void		beSigned(Bureaucrat &b);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif // FORM_HPP
