#include "Zombie.hpp"

int	main()
{
	Zombie		*myZombieHorde;
	unsigned	nb;
	unsigned	i;

	nb = 5;
	myZombieHorde = zombieHorde(nb, "Carousel");
	i = 0;
	while (i < nb)
	{
		myZombieHorde[i].announce();
		i++;
	}
	delete[] myZombieHorde;
	return (0);
}