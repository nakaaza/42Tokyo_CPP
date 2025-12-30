#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &src);
	FragTrap &operator=(const FragTrap &rhs);
	virtual ~FragTrap();

	virtual void	attack(const std::string& target);
	void			highFiveGuys(void);
};

#endif // FRAG_TRAP_HPP
