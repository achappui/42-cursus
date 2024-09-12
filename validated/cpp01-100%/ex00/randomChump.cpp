#include <string>
#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	myStaticZombie;

	myStaticZombie.renameZombie(name);
	myStaticZombie.announce();
}