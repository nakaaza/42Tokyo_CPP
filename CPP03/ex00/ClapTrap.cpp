#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap():
	name(""),
	hit_points(10),
	energy_points(10),
	attck_damage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
	return ; 
}

ClapTrap::ClapTrap(const ClapTrap &src):
	name(src.name),
	hit_points(src.hit_points),
	energy_points(src.energy_points),
	attck_damage(src.attck_damage)
{
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "Copy ClapTrap assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
		this->hit_points = rhs.hit_points;
		this->energy_points = rhs.energy_points;
		this->attck_damage = rhs.attck_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->name
				  << " doesn't have enough points to attack."
				  << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target
			  << ", causing " << this->attck_damage << " points of damage!"
			  << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {

}

void	ClapTrap::beRepaired(unsigned int amount) {

}

void	ClapTrap::healthCheck(void) {
	
}
