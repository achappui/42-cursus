#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*myDynamicZombie;

	myDynamicZombie = new Zombie();
	myDynamicZombie->renameZombie(name);
	return (myDynamicZombie);
}