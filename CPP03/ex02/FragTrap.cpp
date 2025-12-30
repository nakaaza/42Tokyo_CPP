#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hit_points_ = 100;
	this->energy_points_ = 100;
	this->attck_damage_ = 30;
	return ; 
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap constructor with name " << this->name_
			  << " called" << std::endl;
	this->hit_points_ = 100;
	this->energy_points_ = 100;
	this->attck_damage_ = 30;
	return ; 
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src) {
	std::cout << "FragTrap copy constructor for " << this->name_
			  << " called" << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	std::cout << "FragTrap copy assignment operator with " << rhs.name_
			  << " called" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor for " << this->name_
			  << " called" << std::endl;
	return ;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->isActionable())
	{
		this->consumeEnegyPoint();
		std::cout << "FragTrap " << this->name_ << " attacks " << target
				  << ", causing " << this->attck_damage_ << " points of damage!"
				  << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->name_
				  << " can't attack anymore..."
				  << std::endl;
	}
	this->healthCheck();
	return ;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->name_
			  << " said: \"High-Five, Guys!!\""
			  << std::endl;
	return ;
}
