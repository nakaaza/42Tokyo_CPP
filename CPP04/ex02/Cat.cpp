#include "Cat.hpp"
#include <iostream>

Cat::Cat(): AAnimal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
	return ; 
}

Cat::Cat(const Cat &src): AAnimal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
}

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs)
	{
		AAnimal::operator=(rhs);
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

void	Cat::makeSound() const
{
	std::cout << "MEOW" << std::endl;
	return ;
}

void	Cat::setIdea(size_t idx, std::string idea)
{
	this->brain->set_idea(idx, idea);
}

std::string	Cat::getIdea(size_t idx) const
{
	return (this->brain->get_idea(idx));
}
