#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <string>

class WrongAnimal {

protected:
	std::string	type;	

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal &operator=(const WrongAnimal &rhs);
	virtual ~WrongAnimal();

	virtual void	makeSound() const;
	std::string		getType() const;
};

#endif // WRONG_ANIMAL_HPP
