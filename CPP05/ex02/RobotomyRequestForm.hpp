#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm {

private:
	std::string	_target;

	RobotomyRequestForm();

	virtual void	doExecute() const;
	

public:
	RobotomyRequestForm(const std::string	target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
	~RobotomyRequestForm();

};

#endif // ROBOTOMY_REQUEST_FORM_HPP
