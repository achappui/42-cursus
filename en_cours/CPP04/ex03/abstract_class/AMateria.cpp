#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria()
	:	m_type("none")
{
	std::cout << GREEN;
	std::cout << "AMateria default constructor called" << std::endl;
	std::cout << RESET;
}

AMateria::AMateria(const std::string& type)
	:	m_type(type)
{
	std::cout << GREEN;
	std::cout << "AMateria type constructor called" << std::endl;
	std::cout << RESET;
}

AMateria::AMateria(const AMateria& other)
	:	m_type(other.m_type)
{
	std::cout << GREEN;
	std::cout << "AMateria copy constructor called" << std::endl;
	std::cout << RESET;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		m_type = other.m_type;
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << RED;
	std::cout << "AMateria destructor called" << std::endl;
	std::cout << RESET;
}

const std::string&	AMateria::getType(void) const {return (m_type);}
