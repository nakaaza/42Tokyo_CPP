#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
	return ; 
}

Animal::Animal(const Animal &src): type(src.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

void	Animal::makeSound() const
{
	std::cout << "(Oh, it's a surprise that you can hear me. I'm ἀρχή, the origin of all the living things.)" << std::endl;
	return ;
}

std::string	Animal::getType() const
{
	return (this->type);
}
