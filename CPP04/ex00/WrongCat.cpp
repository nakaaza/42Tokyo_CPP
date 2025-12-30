#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
	return ; 
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	if (this != &rhs)
		WrongAnimal::operator=(rhs);
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

void	WrongCat::makeSound() const
{
	std::cout << "MMMeowZZZ" << std::endl;
	return ;
}
