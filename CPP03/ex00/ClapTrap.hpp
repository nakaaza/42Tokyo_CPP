#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

class ClapTrap {

private:
	std::string	name;
	int			hit_points;
	int			energy_points;
	int			attck_damage;

public:
	ClapTrap();
	ClapTrap(const ClapTrap &src);
	ClapTrap &operator=(const ClapTrap &rhs);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	healthCheck(void);
};

#endif // CLAP_TRAP_HPP
