#include "Zombie.hpp"

int	main(void)
{
	Zombie	*dynamicZombie1;
	Zombie	*dynamicZombie2;

	randomChump("Alan");
	dynamicZombie1 = newZombie("Geser");
	randomChump("Rene");
	dynamicZombie2 = newZombie("Pat");
	delete dynamicZombie1;
	delete dynamicZombie2;
	return (0);
}