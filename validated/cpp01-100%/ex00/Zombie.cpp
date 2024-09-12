#include <iostream>
#include "colors.hpp"
#include "Zombie.hpp"

Zombie::Zombie() : m_name("Zombie")
{
	std::cout << GREEN;
	std::cout << "A Zombie got created." << std::endl;
	std::cout << RESET;
}

Zombie::Zombie(const Zombie& other)
{
	this->m_name = other.m_name;
}

Zombie&	Zombie::operator=(const Zombie& other)
{
	if (this != &other)
	{
		this->m_name = other.m_name;
	}
	return (*this);
}

Zombie::~Zombie()
{
	std::cout << RED;
	std::cout << "A zombie named " << m_name << " got deleted." << std::endl;
	std::cout << RESET;
}

void	Zombie::announce(void)
{
	std::cout << OLIVE;
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	std::cout << RESET;
}

void	Zombie::renameZombie(std::string newName)
{
	m_name = newName;
}