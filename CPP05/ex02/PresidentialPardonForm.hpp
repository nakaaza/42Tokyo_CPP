#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm {

private:
	PresidentialPardonForm();

	virtual void	doExecute() const;
	

public:
	PresidentialPardonForm(const std::string	target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	~PresidentialPardonForm();

};

#endif // PRESIDENTIAL_PARDON_FORM_HPP
