#include <iostream>
#include "colors.hpp"
#include "HumanB.hpp"

HumanB::HumanB(const std::string name)
	:	m_name(name),
		m_weapon(NULL)
{
	std::cout << GREEN;
	std::cout << "A HumanB got created." << std::endl;
	std::cout << RESET;
}

HumanB::HumanB(const HumanB& other)
	:	m_name(other.m_name), 
		m_weapon(other.m_weapon)
{
	std::cout << GREEN;
	std::cout << "A HumanB got created." << std::endl;
	std::cout << RESET;
}

HumanB::~HumanB()
{
	std::cout << RED;
	std::cout << "A HumanB named " << m_name << " got deleted." <<std::endl;
	std::cout << RESET;
}

void	HumanB::attack(void)
{
	if (m_weapon)
		std::cout << m_name << " attack with their " << m_weapon->getType() << std::endl;
	else
		std::cout << m_name << " attack with their " << "hands" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {this->m_weapon = &weapon;}