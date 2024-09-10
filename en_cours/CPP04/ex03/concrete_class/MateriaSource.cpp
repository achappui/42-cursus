#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
	:	m_storage(),
		m_storageIsFull(false),
		m_lastLearnedIdx(-1),
		m_knownTypes()
{
	m_knownTypes[0] = TYPE_0;
	m_knownTypes[1] = TYPE_1;
	for (unsigned i = 0; i < STORAGE_SIZE; i++)
		m_storage[i] = NULL;
	std::cout << GREEN;
	std::cout << "MateriaSource default constructor called" << std::endl;
	std::cout << RESET;
}

MateriaSource::MateriaSource(const MateriaSource& other)
	:	m_storage(),
		m_storageIsFull(other.m_storageIsFull),
		m_lastLearnedIdx(other.m_lastLearnedIdx),
		m_knownTypes()
{
	m_knownTypes[0] = TYPE_0;
	m_knownTypes[1] = TYPE_1;
	for (unsigned i = 0; i < STORAGE_SIZE; i++)
		m_storage[i] = other.m_storage[i]->clone();
	std::cout << GREEN;
	std::cout << "MateriaSource copy constructor called" << std::endl;
	std::cout << RESET;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (unsigned i = 0; i < STORAGE_SIZE; i++)
		{
			delete m_storage[i];
			m_storage[i] = other.m_storage[i]->clone();
		}
		m_storageIsFull = other.m_storageIsFull;
		m_lastLearnedIdx = other.m_lastLearnedIdx;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (unsigned i = 0; i < STORAGE_SIZE; i++)
		delete m_storage[i];
	std::cout << RED;
	std::cout << "MateriaSource destructor called" << std::endl;
	std::cout << RESET;
}


AMateria*	MateriaSource::createMateria(const std::string& type)
{
	long		i;

	if (!isInKnownTypes(type))
	{
		std::cout << MATERIASOURCE_COLOR;
		std::cout << "Unknown materia !" << std::endl;
		std::cout << RESET;
		return (NULL);
	}
	if (m_lastLearnedIdx == -1)
	{
		std::cout << MATERIASOURCE_COLOR;
		std::cout << "No materia in the storage !" << std::endl;
		std::cout << RESET;
		return (NULL);
	}
	i = m_lastLearnedIdx;
	while (i >= 0)
	{
		if (m_storage[i]->getType() == type)
			return (m_storage[i]->clone());
		i--;
	}
	std::cout << MATERIASOURCE_COLOR;
	std::cout << "No materia matching the given type !" << std::endl;
	std::cout << RESET;
	return (NULL);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (m_storageIsFull)
	{
		std::cout << MATERIASOURCE_COLOR;
		std::cout << "Learning capacity already at max !" << std::endl;
		std::cout << RESET;
		return ;
	}
	for (unsigned i = 0; i < STORAGE_SIZE; i++)
	{
		if (m_storage[i] == NULL)
		{
			m_storage[i] = m;
			m_lastLearnedIdx = i;
			return ;
		}
	}
	m_storageIsFull = true;
}

bool	MateriaSource::isInKnownTypes(const std::string type)
{
	for (unsigned i = 0; i < KNOWN_TYPES_SIZE; i++)
	{
		if (m_knownTypes[i] == type)
			return (1);
	}
	return (0);
}