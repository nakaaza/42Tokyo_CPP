#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	return ; 
}

Cat::Cat(const Cat &src): Animal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs)
		Animal::operator=(rhs);
	std::cout << "Cat copy assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

void	Cat::makeSound() const
{
	std::cout << "MEOW" << std::endl;
	return ;
}
