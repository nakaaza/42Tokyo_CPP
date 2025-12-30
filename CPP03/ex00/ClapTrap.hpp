#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>

class ClapTrap {

private:
	std::string		name_;
	unsigned int	hit_points_;
	unsigned int	energy_points_;
	unsigned int	attck_damage_;

	bool	isAlive(void);
	bool	isActionable(void);
	bool	healthCheck(void);
	void	consumeEnegyPoint(void);
	void	consumeHitPoint(unsigned int amount);
	void	gainHitPoint(unsigned int amount);

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &src);
	ClapTrap &operator=(const ClapTrap &rhs);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	setName(const std::string name);
};

#endif // CLAP_TRAP_HPP
