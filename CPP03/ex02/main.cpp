#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
	ClapTrap clap1("CLAP1");
	ClapTrap clap2;
	ClapTrap clap3;
	ScavTrap scav1("SCAV1");
	ScavTrap scav2(scav1);
	FragTrap frag1("FRAG1");
	FragTrap frag2(frag1);
	clap2 = scav1;
	clap3 = frag1;

	clap2.setName("CLAP2");
	clap3.setName("CLAP3");
	scav2.setName("SCAV2");
	frag2.setName("FRAG2");

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

	std::cout << std::endl << "=== Basic tests with CLAP3 =====" << std::endl;
	clap3.attack("ENEMY");
	clap3.beRepaired(5);
	clap3.takeDamage(10);
	clap3.takeDamage(10);

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

	std::cout << std::endl << "=== Basic tests with FRAG1 =====" << std::endl;
	frag1.attack("ENEMY");
	frag1.beRepaired(5);
	frag1.takeDamage(10);
	frag1.takeDamage(10);
	frag1.highFiveGuys();

	std::cout << std::endl << "=== Basic tests with FRAG2 =====" << std::endl;
	frag2.attack("ENEMY");
	frag2.beRepaired(5);
	frag2.takeDamage(10);
	frag2.takeDamage(10);
}
