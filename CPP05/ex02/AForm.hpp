#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>

class Bureaucrat;

class AForm {

private:
	const static int	HIGHEST_GRADE;
	const static int	LOWEST_GRADE;

	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	bool				_signed;

	static bool			validateGrade(int grade);

public:
	AForm();
	AForm(const AForm &src);
	AForm(std::string name,
		 int gradeToSign = HIGHEST_GRADE,
		 int gradeToExecute = HIGHEST_GRADE,
		 bool sign = false
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
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif // AForm_HPP
