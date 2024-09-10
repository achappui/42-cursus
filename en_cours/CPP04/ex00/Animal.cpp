#include <iostream>
#include "Animal.hpp"

Animal::Animal()
	:	m_type("Unknown")
{
	std::cout << GREEN;
	std::cout << "Animal contructor called" << std::endl;
	std::cout << RESET;
}

Animal::Animal(const Animal& other)
	:	m_type(other.m_type)
{
	std::cout << GREEN;
	std::cout << "Animal copy contructor called" << std::endl;
	std::cout << RESET;
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
		m_type = other.m_type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << RED;
	std::cout << "Animal destructor called" << std::endl;
	std::cout << RESET;
}

void	Animal::makeSound(void) const
{
	std::cout << m_type << " makes some sound: None !" << std::endl;
}

std::string	Animal::getType(void) const {return (m_type);}