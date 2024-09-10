#include <iostream>
#include "Dog.hpp"

Dog::Dog()
	:	Animal()
{
	m_type = "Dog";
	std::cout << GREEN;
	std::cout << "Dog contructor called" << std::endl;
	std::cout << RESET;
}

Dog::Dog(const Dog& other)
	:	Animal()
{
	m_type = other.m_type;
	std::cout << GREEN;
	std::cout << "Dog copy contructor called" << std::endl;
	std::cout << RESET;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
		m_type = other.m_type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << RED;
	std::cout << "Dog destructor called" << std::endl;
	std::cout << RESET;
}

void	Dog::makeSound(void) const
{
	std::cout << m_type << " makes some sound: Wouaf !" << std::endl;
}

std::string	Dog::getType(void) const {return (m_type);}