#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal {

private:
	Brain*	brain;

public:
	Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &rhs);
	virtual	~Cat();

	virtual void	makeSound() const;
	void			setIdea(size_t idx, std::string idea);
	std::string		getIdea(size_t idx) const;
};

#endif // CAT_HPP
