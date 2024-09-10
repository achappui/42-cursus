#include <iostream>
#include "Cure.hpp"

Cure::Cure()
	:	AMateria()
{
	m_type = "cure";
	std::cout << GREEN;
	std::cout << "Cure default constructor called" << std::endl;
	std::cout << RESET;
}

Cure::Cure(const std::string& type)
	:	AMateria()
{
	m_type = type;
	std::cout << GREEN;
	std::cout << "Cure type constructor called" << std::endl;
	std::cout << RESET;
}

Cure::Cure(const Cure& other)
	:	AMateria()
{
	m_type = other.m_type;
	std::cout << GREEN;
	std::cout << "Cure copy constructor called" << std::endl;
	std::cout << RESET;
}

Cure&	Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		m_type = other.m_type;
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << RED;
	std::cout << "Cure destructor called" << std::endl;
	std::cout << RESET;
}


void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " *" << std::endl;
}

Cure*	Cure::clone(void) const
{
	Cure	*newCure;

	newCure = new Cure();
	*newCure = *this;
	return (newCure);
}