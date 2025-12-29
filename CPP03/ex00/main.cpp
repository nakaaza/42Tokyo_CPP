#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap clap1("CLAP1");
	ClapTrap clap2(clap1);
	ClapTrap clap3;
	clap3 = clap1;

	clap2.setName("CLAP2");
	clap3.setName("CLAP3");

	std::cout << std::endl << "=== Basic tests with CLAP1 =====" << std::endl;
	clap1.attack("ENEMY");
	clap1.beRepaired(5);
	clap1.takeDamage(10);
	clap1.takeDamage(10);

	std::cout << std::endl << "=== attack() exhaution test with CLAP2 =====" << std::endl;
	int	i = 12;
	while (--i > 0)
		clap2.attack("ENEMY");

	std::cout << std::endl << "=== beRepaired() exhaution test with CLAP3 =====" << std::endl;
	i = 12;
	while (--i > 0)
		clap3.beRepaired(1);
	return 0;
}
