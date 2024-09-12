#include <iostream>
#include "colors.hpp"
#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon)
	:	m_name(name), 
		m_weapon(weapon)
{
	std::cout << GREEN;
	std::cout << "A HumanA got created." << std::endl;
	std::cout << RESET;
}

HumanA::HumanA(const HumanA& other)
	:	m_name(other.m_name), 
		m_weapon(other.m_weapon)
{
	std::cout << GREEN << "A HumanA got created." << RESET <<std::endl;
}

HumanA::~HumanA()
{
	std::cout << RED;
	std::cout << "A HumanA named " << m_name << " got deleted." <<std::endl;
	std::cout << RESET;
}

void	HumanA::attack(void)
{
	std::cout << m_name << " attack with their " << m_weapon.getType() << std::endl;
}
