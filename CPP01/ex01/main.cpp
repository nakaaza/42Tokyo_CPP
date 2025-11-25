#include <iostream>
#include "Zombie.hpp"

int	main()
{
	int			N = 7;
	std::string	name = "ZomZom";
	Zombie		*horde = zombieHorde(7, "ZomZom");

	int i = -1;
	while (++i < N)
	{
		std::cout << "[" << i << "] ";
		horde[i].announce();
	}

	delete[] horde;
	return (0);
}
