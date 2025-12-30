#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <string>

class AAnimal {

protected:
	std::string	type;	
	

public:
	AAnimal();
	AAnimal(const AAnimal &src);
	AAnimal &operator=(const AAnimal &rhs);
	virtual ~AAnimal();

	virtual void	makeSound() const = 0;
	std::string		getType() const;
};

#endif // AAnimal_HPP
