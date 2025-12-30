#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal {

public:
	Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &rhs);
	virtual	~Cat();

	virtual void	makeSound() const;
};

#endif // CAT_HPP
