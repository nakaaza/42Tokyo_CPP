#include "Brain.hpp"
#include <iostream>
#include <stdexcept>

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	return ; 
}

Brain::Brain(const Brain &src) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < Brain::idea_count; i++)
		ideas[i] = src.ideas[i];
}

Brain &Brain::operator=(const Brain &rhs) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &rhs) {
		*this->ideas = *rhs.ideas;
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

void	Brain::set_idea(size_t idx, std::string idea)
{
	if (idx < 0 || idx >= Brain::idea_count)
		throw std::out_of_range("idx out of range");
	this->ideas[idx] = idea;
}

std::string	Brain::get_idea(size_t idx) const
{
	if (idx < 0 || idx >= Brain::idea_count)
		throw std::out_of_range("idx out of range");
	return (this->ideas[idx]);
}
