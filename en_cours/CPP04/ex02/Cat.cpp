#include <iostream>
#include "Cat.hpp"

Cat::Cat()
	:	Animal(), m_brain(new Brain())
{
	m_type = "Cat";

	std::string	*catIdeas = m_brain->getIdeas();
	for (unsigned i = 0; i < NB_OF_IDEAS; i++)
		catIdeas[i] = "I am a cat, so I eat mice !";
	std::cout << GREEN;
	std::cout << "Cat contructor called" << std::endl;
	std::cout << RESET;
}

Cat::Cat(const Cat& other)
	:	Animal(), m_brain(new Brain())
{
	*m_brain = *other.m_brain;
	m_type = other.m_type;
	std::cout << GREEN;
	std::cout << "Cat copy contructor called" << std::endl;
	std::cout << RESET;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		*m_brain = *other.m_brain;
		m_type = other.m_type;
	}
	return (*this);
}

Cat::~Cat()
{
	delete m_brain;
	std::cout << RED;
	std::cout << "Cat destructor called" << std::endl;
	std::cout << RESET;
}

void	Cat::makeSound(void) const
{
	std::cout << m_type << " makes some sound: Miaou !" << std::endl;
}

std::string	Cat::getType(void) const {return (m_type);}

void		Cat::printFirstIdea(void) const
{
	std::cout << m_type << " idea: " << m_brain->getIdeas()[0] << std::endl;
}