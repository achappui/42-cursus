#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	:	ClapTrap()
{
	m_name = "Default ScavTrap";
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	std::cout << GREEN;
	std::cout << "ScavTrap default constructor called" << std::endl;
	std::cout << RESET;
}

ScavTrap::ScavTrap(std::string name)
	:	ClapTrap(name)
{
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	std::cout << GREEN;
	std::cout << "ScavTrap name constructor called" << std::endl;
	std::cout << RESET;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	:	ClapTrap()
{
	m_name = other.m_name;
	m_hitPoints = other.m_hitPoints;
	m_energyPoints = other.m_energyPoints;
	m_attackDamage = other.m_attackDamage;
	std::cout << GREEN;
	std::cout << "ScavTrap copy constructor called" << std::endl;
	std::cout << RESET;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
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

ScavTrap::~ScavTrap()
{
	std::cout << RED;
	std::cout << "ScavTrap destructor called" << std::endl;
	std::cout << RESET;
}


void	ScavTrap::attack(const std::string& target)
{
	std::cout << SCAVTRAP_COLOR;
	if (m_hitPoints == 0)
		std::cout	<< "ScavTrap " << m_name << " is already dead !" << std::endl;
	else
	{
		if (m_energyPoints == 0)
		{
			std::cout	<< "ScavTrap " << m_name << " missed " << target
						<< ". No more energy points !" << std::endl;	
		}
		else
		{
			m_energyPoints -= 1;
			std::cout	<< "ScavTrap " << m_name << " attacks " << target
						<< ", causing " <<  m_attackDamage << " points of damage !"
						<< std::endl;
		}

	}
	std::cout << RESET;
}

void	ScavTrap::takeDamage(unsigned amount)
{
	std::cout << SCAVTRAP_COLOR;
	if (m_hitPoints == 0)
		std::cout	<< "ScavTrap " << m_name << " is already dead ! " << std::endl;
	else if (m_hitPoints <= amount)
	{
		std::cout	<< "ScavTrap " << m_name << " takes " << amount << " damages "
					<< "and dies !" << std::endl;
		m_hitPoints = 0;
	}
	else if (m_hitPoints > amount)
	{
		std::cout	<< "ScavTrap " << m_name << " takes " << amount << " damages !"
					<< std::endl;
		m_hitPoints -= amount;
	}
	std::cout << RESET;
}

void	ScavTrap::beRepaired(unsigned amount)
{
	std::cout << SCAVTRAP_COLOR;
	if (m_hitPoints == 0)
		std::cout	<< "ScavTrap " << m_name << " is already dead ! " << std::endl;
	else
	{
		if (m_energyPoints == 0)
		{
			std::cout	<< "ScavTrap " << m_name << " cannot repair itself. "
						<< "No more energy points !" << std::endl;
		}
		else if (m_hitPoints == 10)
		{
			std::cout	<< "ScavTrap " << m_name << " is already at max hit points !"
						<< std::endl;
		}
		else if (m_hitPoints < 10)
		{
			m_energyPoints -= 1;
			if (10 - m_hitPoints <= amount)
				m_hitPoints = 10;
			else
				m_hitPoints += amount;
			std::cout	<< "ScavTrap " << m_name << " repairs itself by " << amount
						<< " hit points !" << std::endl;
		}
	}
	std::cout << RESET;
}

void	ScavTrap::guardGate(void)
{
	std::cout << SCAVTRAP_COLOR;
	if (m_hitPoints == 0)
		std::cout	<< "ScavTrap " << m_name << " is already dead ! " << std::endl;
	else
		std::cout << "ScavTrap " << m_name << " is now in gate keeper mode !" << std::endl;
	std::cout << RESET;
}