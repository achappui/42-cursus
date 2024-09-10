#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	:	m_name("Default DiamondTrap"),
		m_hitPoints(FragTrap::m_hitPoints),
		m_energyPoints(ScavTrap::m_energyPoints),
		m_attackDamage(FragTrap::m_attackDamage)
{
	std::cout << GREEN;
	std::cout << "DiamondTrap default constructor called" << std::endl;
	std::cout << RESET;
}

DiamondTrap::DiamondTrap(std::string name)
	:	ScavTrap(name + "_clap_name"), 
		FragTrap(name + "_clap_name"),
		m_name(name),
		m_hitPoints(FragTrap::m_hitPoints),
		m_energyPoints(ScavTrap::m_energyPoints),
		m_attackDamage(FragTrap::m_attackDamage)
{

	std::cout << GREEN;
	std::cout << "DiamondTrap name constructor called" << std::endl;
	std::cout << RESET;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	:	ClapTrap(), 
		ScavTrap(), 
		FragTrap(),
		m_name(other.m_name),
		m_hitPoints(other.m_hitPoints),
		m_energyPoints(other.m_energyPoints),
		m_attackDamage(other.m_attackDamage)
{
	std::cout << GREEN;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	std::cout << RESET;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		this->m_name = other.m_name;
		this->m_hitPoints = other.m_hitPoints;
		this->m_energyPoints = other.m_energyPoints;
		this->m_attackDamage = other.m_attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED;
	std::cout << "DiamondTrap destructor called" << std::endl;
	std::cout << RESET;
}


void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << m_name << " and my ClapTrap name is " << FragTrap::m_name << std::endl;
}

void	DiamondTrap::displayAttributs(void)
{
	std::cout << "m_name : " << m_name << std::endl;
	std::cout << "m_hitPoints : " << m_hitPoints << std::endl;
	std::cout << "m_energyPoints : " << m_energyPoints << std::endl;
	std::cout << "m_attackDamage : " << m_attackDamage << std::endl;
}
