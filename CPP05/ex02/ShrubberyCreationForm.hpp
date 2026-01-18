#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm {

private:
	ShrubberyCreationForm();

	virtual void	doExecute() const;
	

public:
	ShrubberyCreationForm(const std::string	target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm();

};

#endif // SHRUBBERY_CREATION_FORM_HPP
