#include "Zombie.hpp"

Zombie*	zombieHorde(unsigned n, std::string name)
{
	Zombie		*zombieHorde;
	unsigned	i;

	zombieHorde = new Zombie[n];
	i = 0;
	while (i < n)
	{
		zombieHorde[i].renameZombie(name);
		i++;
	}
	return (zombieHorde);
}