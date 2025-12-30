#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &src);
	ScavTrap &operator=(const ScavTrap &rhs);
	virtual ~ScavTrap();

	virtual void	attack(const std::string& target);
	void			guardGate();
};

#endif // SCAV_TRAP_HPP
