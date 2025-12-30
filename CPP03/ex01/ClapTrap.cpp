#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap():
	name_(""),
	hit_points_(10),
	energy_points_(10),
	attck_damage_(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	return ; 
}

ClapTrap::ClapTrap(std::string name):
	name_(name),
	hit_points_(10),
	energy_points_(10),
	attck_damage_(0)
{
	std::cout << "ClapTrap constructor with name " << this->name_
			  << " called" << std::endl;
	return ; 
}

ClapTrap::ClapTrap(const ClapTrap &src):
	name_(src.name_),
	hit_points_(src.hit_points_),
	energy_points_(src.energy_points_),
	attck_damage_(src.attck_damage_)
{
	std::cout << "ClapTrap copy constructor for " << this->name_
			  << " called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap copy assignment operator with " << rhs.name_
			  << " called" << std::endl;
	if (this != &rhs) {
		this->name_ = rhs.name_;
		this->hit_points_ = rhs.hit_points_;
		this->energy_points_ = rhs.energy_points_;
		this->attck_damage_ = rhs.attck_damage_;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor for " << this->name_
			  << " called" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->isActionable())
	{
		this->consumeEnegyPoint();
		std::cout << "ClapTrap " << this->name_ << " attacks " << target
				<< ", causing " << this->attck_damage_ << " points of damage!"
				<< std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name_
				  << " can't attack anymore..."
				  << std::endl;
	}
	this->healthCheck();
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->consumeHitPoint(amount);

	std::cout << "ClapTrap " << this->name_ << " took "
			  << amount << " points of damage!"
			  << std::endl;
	this->healthCheck();
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->isActionable())
	{
		this->consumeEnegyPoint();
		this->gainHitPoint(amount);
		std::cout << "ClapTrap " << this->name_
				  << " is repaired with " << amount << " EP."
				  << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name_
				  << " can't be repaired anymore..."
				  << std::endl;
	}
	this->healthCheck();
	return ;
}

bool	ClapTrap::isAlive(void)
{
	return (this->hit_points_ > 0);
}

bool	ClapTrap::isActionable(void)
{
	return (this->isAlive() && this->energy_points_ > 0);
}

bool	ClapTrap::healthCheck(void)
{
	bool	res = true;
	std::cout << "[healthCheck] ClapTrap " << this->name_
			  << " has " << this->hit_points_
			  << "HP and " << this->energy_points_
			  << "EP now." << std::endl;
	if (!this->isAlive()) {
		std::cout << "-> ClapTrap " << this->name_
				  << " is dead..." << std::endl;
		res = false;
	}
	else if (!this->isActionable()) {
		std::cout << "-> ClapTrap " << this->name_
				  << " can't take action anymore..." << std::endl;
		res = false;
	}
	std::cout << std::endl;
	return (res);
}

void	ClapTrap::consumeEnegyPoint(void)
{
	if (this->isActionable())
		--this->energy_points_;
	return ;
}

void	ClapTrap::consumeHitPoint(unsigned int amount)
{
	if (this->hit_points_ > amount)
		this->hit_points_ -= amount;
	else
		this->hit_points_ = 0;
	return ;
}

void	ClapTrap::gainHitPoint(unsigned int amount)
{
	this->hit_points_ += amount;
	return ;
}

void	ClapTrap::setName(const std::string name)
{
	std::cout << "ClapTrap " << this->name_
			  << " is now called " << name << std::endl;
	this->name_ = name;
	return ;
}
