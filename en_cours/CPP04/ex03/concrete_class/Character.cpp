#include <iostream>
#include "Character.hpp"

Character::Character()
	:	m_name("none"),
		m_inventory(),
		m_inventoryIsFull(false)
{
	for (unsigned i = 0; i < INVENTORY_SIZE; i++)
		m_inventory[i] = NULL;
	std::cout << GREEN;
	std::cout << "Character default constructor called" << std::endl;
	std::cout << RESET;
}

Character::Character(const std::string name)
	:	m_name(name),
		m_inventory(),
		m_inventoryIsFull(false)
{
	for (unsigned i = 0; i < INVENTORY_SIZE; i++)
		m_inventory[i] = NULL;
	std::cout << GREEN;
	std::cout << "Character name constructor called" << std::endl;
	std::cout << RESET;
}

Character::Character(const Character& other)
	:	m_name(other.m_name),
		m_inventory(),
		m_inventoryIsFull(other.m_inventoryIsFull)
{
	for (unsigned i = 0; i < INVENTORY_SIZE; i++)
		m_inventory[i] = other.m_inventory[i]->clone();
	std::cout << GREEN;
	std::cout << "Character copy constructor called" << std::endl;
	std::cout << RESET;
}

Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		m_name = other.m_name;
		for (unsigned i = 0; i < INVENTORY_SIZE; i++)
		{
			delete m_inventory[i];
			m_inventory[i] = other.m_inventory[i]->clone();
		}
		m_inventoryIsFull = other.m_inventoryIsFull;
	}
	return (*this);
}

Character::~Character()
{
	for (unsigned i = 0; i < INVENTORY_SIZE; i++)
		delete m_inventory[i];
	std::cout << RED;
	std::cout << "Character destructor called" << std::endl;
	std::cout << RESET;
}

const std::string&	Character::getName() const {return (m_name);}

void	Character::equip(AMateria* m)
{
	if (m_inventoryIsFull)
	{
		std::cout << CHARACTER_COLOR;
		std::cout << "The inventory is already full !" << std::endl;
		std::cout << RESET;
		return ;
	}
	for (unsigned i = 0; i < INVENTORY_SIZE; i++)
	{
		if (m_inventory[i] == NULL)
		{
			m_inventory[i] = m;
			return ;
		}
	}
	m_inventoryIsFull = true;
}

void	Character::unequip(int idx)
{
	if (m_inventory[idx] == NULL)
	{
		std::cout << CHARACTER_COLOR;
		std::cout << "Nothing in inventory at index " << idx << " !" << std::endl;
		std::cout << RESET;
		return ;
	}
	m_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (m_inventory[idx] == NULL)
	{
		std::cout << CHARACTER_COLOR;
		std::cout << "Nothing in inventory at index " << idx << " !" << std::endl;
		std::cout << RESET;
		return ;
	}
	m_inventory[idx]->use(target);
}
