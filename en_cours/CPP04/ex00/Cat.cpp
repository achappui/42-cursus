#include <iostream>
#include "Cat.hpp"

Cat::Cat()
	:	Animal()
{
	m_type = "Cat";
	std::cout << GREEN;
	std::cout << "Cat contructor called" << std::endl;
	std::cout << RESET;
}

Cat::Cat(const Cat& other)
	:	Animal()
{
	m_type = other.m_type;
	std::cout << GREEN;
	std::cout << "Cat copy contructor called" << std::endl;
	std::cout << RESET;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
		m_type = other.m_type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << RED;
	std::cout << "Cat destructor called" << std::endl;
	std::cout << RESET;
}

void	Cat::makeSound(void) const
{
	std::cout << m_type << " makes some sound: Miaou !" << std::endl;
}

std::string	Cat::getType(void) const {return (m_type);}