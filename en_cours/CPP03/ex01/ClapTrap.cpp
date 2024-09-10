#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:	m_name("Default ClapTrap"),
		m_hitPoints(10),
		m_energyPoints(10),
		m_attackDamage(0)
{
	std::cout << GREEN;
	std::cout << "ClapTrap default constructor called" << std::endl;
	std::cout << RESET;
}

ClapTrap::ClapTrap(std::string name)
	:	m_name(name),
		m_hitPoints(10),
		m_energyPoints(10),
		m_attackDamage(0)
{
	std::cout << GREEN;
	std::cout << "ClapTrap name constructor called" << std::endl;
	std::cout << RESET;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	:	m_name(other.m_name),
		m_hitPoints(other.m_hitPoints),
		m_energyPoints(other.m_energyPoints),
		m_attackDamage(other.m_attackDamage)
{
	std::cout << GREEN;
	std::cout << "ClapTrap copy constructor called" << std::endl;
	std::cout << RESET;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
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

ClapTrap::~ClapTrap()
{
	std::cout << RED;
	std::cout << "ClapTrap destructor called" << std::endl;
	std::cout << RESET;
}


void	ClapTrap::attack(const std::string& target)
{
	std::cout << CLAPTRAP_COLOR;
	if (m_hitPoints == 0)
		std::cout	<< "ClapTrap " << m_name << " is already dead !" << std::endl;
	else
	{
		if (m_energyPoints == 0)
		{
			std::cout	<< "ClapTrap " << m_name << " missed " << target
						<< ". No more energy points !" << std::endl;	
		}
		else
		{
			m_energyPoints -= 1;
			std::cout	<< "ClapTrap " << m_name << " attacks " << target
						<< ", causing " <<  m_attackDamage << " points of damage !"
						<< std::endl;
		}

	}
	std::cout << RESET;
}

void	ClapTrap::takeDamage(unsigned amount)
{
	std::cout << CLAPTRAP_COLOR;
	if (m_hitPoints == 0)
		std::cout	<< "ClapTrap " << m_name << " is already dead ! " << std::endl;
	else if (m_hitPoints <= amount)
	{
		std::cout	<< "ClapTrap " << m_name << " takes " << amount << " damages "
					<< "and dies !" << std::endl;
		m_hitPoints = 0;
	}
	else if (m_hitPoints > amount)
	{
		std::cout	<< "ClapTrap " << m_name << " takes " << amount << " damages !"
					<< std::endl;
		m_hitPoints -= amount;
	}
	std::cout << RESET;
}

void	ClapTrap::beRepaired(unsigned amount)
{
	std::cout << CLAPTRAP_COLOR;
	if (m_hitPoints == 0)
		std::cout	<< "ClapTrap " << m_name << " is already dead ! " << std::endl;
	else
	{
		if (m_energyPoints == 0)
		{
			std::cout	<< "ClapTrap " << m_name << " cannot repair itself. "
						<< "No more energy points !" << std::endl;
		}
		else if (m_hitPoints == 10)
		{
			std::cout	<< "ClapTrap " << m_name << " is already at max hit points !"
						<< std::endl;
		}
		else if (m_hitPoints < 10)
		{
			m_energyPoints -= 1;
			if (10 - m_hitPoints <= amount)
				m_hitPoints = 10;
			else
				m_hitPoints += amount;
			std::cout	<< "ClapTrap " << m_name << " repairs itself by " << amount
						<< " hit points !" << std::endl;
		}
	}
	std::cout << RESET;
}
