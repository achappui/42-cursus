#include <iostream>
#include "Ice.hpp"

Ice::Ice()
	:	AMateria()
{
	m_type = "ice";
	std::cout << GREEN;
	std::cout << "Ice default constructor called" << std::endl;
	std::cout << RESET;
}

Ice::Ice(const std::string& type)
	:	AMateria()
{
	m_type = type;
	std::cout << GREEN;
	std::cout << "Ice type constructor called" << std::endl;
	std::cout << RESET;
}

Ice::Ice(const Ice& other)
	:	AMateria()
{
	m_type = other.m_type;
	std::cout << GREEN;
	std::cout << "Ice copy constructor called" << std::endl;
	std::cout << RESET;
}

Ice&	Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		m_type = other.m_type;
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << RED;
	std::cout << "Ice destructor called" << std::endl;
	std::cout << RESET;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice*	Ice::clone(void) const
{
	Ice	*newIce;

	newIce = new Ice();
	*newIce = *this;
	return (newIce);
}
