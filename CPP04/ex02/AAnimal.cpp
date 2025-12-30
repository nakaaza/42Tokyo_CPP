#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(): type("ἀρχή") {
	std::cout << "AAnimal default constructor called" << std::endl;
	return ; 
}

AAnimal::AAnimal(const AAnimal &src): type(src.type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
	return ;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}
