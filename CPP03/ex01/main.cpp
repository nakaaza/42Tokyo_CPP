#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	ClapTrap clap1("CLAP1");
	ClapTrap clap2;
	ScavTrap scav1("SCAV1");
	ScavTrap scav2(scav1);
	clap2 = scav1;

	clap2.setName("CLAP2");
	scav2.setName("SCAV2");

	std::cout << std::endl << "=== Basic tests with CLAP1 =====" << std::endl;
	clap1.attack("ENEMY");
	clap1.beRepaired(5);
	clap1.takeDamage(10);
	clap1.takeDamage(10);

	std::cout << std::endl << "=== Basic tests with CLAP2 =====" << std::endl;
	clap2.attack("ENEMY");
	clap2.beRepaired(5);
	clap2.takeDamage(10);
	clap2.takeDamage(10);

	std::cout << std::endl << "=== Basic tests with SCAV1 =====" << std::endl;
	scav1.attack("ENEMY");
	scav1.beRepaired(5);
	scav1.takeDamage(10);
	scav1.takeDamage(10);
	scav1.guardGate();

	std::cout << std::endl << "=== Basic tests with SCAV2 =====" << std::endl;
	scav2.attack("ENEMY");
	scav2.beRepaired(5);
	scav2.takeDamage(10);
	scav2.takeDamage(10);
}
