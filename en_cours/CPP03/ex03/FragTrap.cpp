#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap()
	:	ClapTrap()
{
	m_name = "Default FragTrap";
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	std::cout << GREEN;
	std::cout << "FragTrap default constructor called" << std::endl;
	std::cout << RESET;
}

FragTrap::FragTrap(std::string name)
	:	ClapTrap(name)
{
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	std::cout << GREEN;
	std::cout << "FragTrap name constructor called" << std::endl;
	std::cout << RESET;
}

FragTrap::FragTrap(const FragTrap& other)
	:	ClapTrap()
{
	m_name = other.m_name;
	m_hitPoints = other.m_hitPoints;
	m_energyPoints = other.m_energyPoints;
	m_attackDamage = other.m_attackDamage;
	std::cout << GREEN;
	std::cout << "FragTrap copy constructor called" << std::endl;
	std::cout << RESET;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
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

FragTrap::~FragTrap()
{
	std::cout << RED;
	std::cout << "FragTrap destructor called" << std::endl;
	std::cout << RESET;
}


void	FragTrap::attack(const std::string& target)
{
	std::cout << FRAGTRAP_COLOR;
	if (m_hitPoints == 0)
		std::cout	<< "FragTrap " << m_name << " is already dead !" << std::endl;
	else
	{
		if (m_energyPoints == 0)
		{
			std::cout	<< "FragTrap " << m_name << " missed " << target
						<< ". No more energy points !" << std::endl;	
		}
		else
		{
			m_energyPoints -= 1;
			std::cout	<< "FragTrap " << m_name << " attacks " << target
						<< ", causing " <<  m_attackDamage << " points of damage !"
						<< std::endl;
		}

	}
	std::cout << RESET;
}

void	FragTrap::takeDamage(unsigned amount)
{
	std::cout << FRAGTRAP_COLOR;
	if (m_hitPoints == 0)
		std::cout	<< "FragTrap " << m_name << " is already dead ! " << std::endl;
	else if (m_hitPoints <= amount)
	{
		std::cout	<< "FragTrap " << m_name << " takes " << amount << " damages "
					<< "and dies !" << std::endl;
		m_hitPoints = 0;
	}
	else if (m_hitPoints > amount)
	{
		std::cout	<< "FragTrap " << m_name << " takes " << amount << " damages !"
					<< std::endl;
		m_hitPoints -= amount;
	}
	std::cout << RESET;
}

void	FragTrap::beRepaired(unsigned amount)
{
	std::cout << FRAGTRAP_COLOR;
	if (m_hitPoints == 0)
		std::cout	<< "FragTrap " << m_name << " is already dead ! " << std::endl;
	else
	{
		if (m_energyPoints == 0)
		{
			std::cout	<< "FragTrap " << m_name << " cannot repair itself. "
						<< "No more energy points !" << std::endl;
		}
		else if (m_hitPoints == 10)
		{
			std::cout	<< "FragTrap " << m_name << " is already at max hit points !"
						<< std::endl;
		}
		else if (m_hitPoints < 10)
		{
			m_energyPoints -= 1;
			if (10 - m_hitPoints <= amount)
				m_hitPoints = 10;
			else
				m_hitPoints += amount;
			std::cout	<< "FragTrap " << m_name << " repairs itself by " << amount
						<< " hit points !" << std::endl;
		}
	}
	std::cout << RESET;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << FRAGTRAP_COLOR;
	if (m_hitPoints == 0)
		std::cout	<< "FragTrap " << m_name << " is already dead ! " << std::endl;
	else
		std::cout << "FragTrap " << m_name << " requests a high five!" << std::endl;
	std::cout << RESET;
}