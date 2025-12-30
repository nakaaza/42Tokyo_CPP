#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {

private:
	Brain*	brain;

public:
	Dog();
	Dog(const Dog &src);
	Dog &operator=(const Dog &rhs);
	virtual	~Dog();

	virtual void	makeSound() const;
	void			setIdea(size_t idx, std::string idea);
	std::string		getIdea(size_t idx) const;
};

#endif // DOG_HPP
