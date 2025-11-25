#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie *z = new Zombie[N];

	int i = -1;
	while (++i < N)
		z[i].setName(name);
	return (z);
}
