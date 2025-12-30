#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hit_points_ = 100;
	this->energy_points_ = 50;
	this->attck_damage_ = 20;
	return ; 
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap constructor with name " << this->name_
			  << " called" << std::endl;
	this->hit_points_ = 100;
	this->energy_points_ = 50;
	this->attck_damage_ = 20;
	return ; 
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src) {
	std::cout << "ScavTrap copy constructor for " << this->name_
			  << " called" << std::endl;
	*this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	std::cout << "ScavTrap copy assignment operator with " << rhs.name_
			  << " called" << std::endl;
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor for " << this->name_
			  << " called" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->isActionable())
	{
		this->consumeEnegyPoint();
		std::cout << "ScavTrap " << this->name_ << " attacks " << target
				  << ", causing " << this->attck_damage_ << " points of damage!"
				  << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->name_
				  << " can't attack anymore..."
				  << std::endl;
	}
	this->healthCheck();
	return ;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name_
			  << " is now in Gate Keeper mode."
			  << std::endl;
	return ;
}
