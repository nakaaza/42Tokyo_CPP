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

protected:
	virtual void	doExecute(Bureaucrat const &executor) const = 0;

public:
	AForm();
	AForm(const AForm &src);
	AForm(std::string name,
		 int gradeToSign = HIGHEST_GRADE,
		 int gradeToExecute = HIGHEST_GRADE,
		 bool sign = false
		);
	AForm &operator=(const AForm &rhs);
	virtual ~AForm();

	std::string	getName() const;
	bool		isSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void		beSigned(Bureaucrat const &signer);
	void		execute(Bureaucrat const &executor) const;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowToSignException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowToExecuteException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class AlreadySignedException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif // AForm_HPP
