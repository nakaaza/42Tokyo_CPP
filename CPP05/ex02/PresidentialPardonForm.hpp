#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm {

private:
	std::string	_target;

	PresidentialPardonForm();

	virtual void	doExecute(Bureaucrat const &executor) const;
	

public:
	PresidentialPardonForm(const std::string	target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	~PresidentialPardonForm();

};

#endif // PRESIDENTIAL_PARDON_FORM_HPP
