#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ; 
}

WrongAnimal::WrongAnimal(const WrongAnimal &src): type(src.type) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "(WWWHat AAARe YYYou DDDoing HHHere?)" << std::endl;
	return ;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}
