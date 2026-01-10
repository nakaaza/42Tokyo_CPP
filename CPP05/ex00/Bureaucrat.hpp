#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;
	const static int	HIGHEST_GRADE;
	const static int	LOWEST_GRADE;

	void				_setGrade(int grade);
	static bool			validateGrade(int grade);

public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade = LOWEST_GRADE);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif // BUREAUCRAT_HPP
