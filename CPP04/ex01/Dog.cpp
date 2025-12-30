#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
	return ; 
}

Dog::Dog(const Dog &src): Animal(src) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

void	Dog::makeSound() const
{
	std::cout << "BOW-WOW" << std::endl;
	return ;
}

void	Dog::setIdea(size_t idx, std::string idea)
{
	this->brain->set_idea(idx, idea);
}

std::string	Dog::getIdea(size_t idx) const
{
	return (this->brain->get_idea(idx));
}
