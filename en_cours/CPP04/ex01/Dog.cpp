#include <iostream>
#include "Dog.hpp"

Dog::Dog()
	:	Animal(), m_brain(new Brain())
{
	m_type = "Dog";
	std::string	*dogIdeas = m_brain->getIdeas();
	for (unsigned i = 0; i < NB_OF_IDEAS; i++)
		dogIdeas[i] = "I'm a dog so I gnaw bones !";
	std::cout << GREEN;
	std::cout << "Dog contructor called" << std::endl;
	std::cout << RESET;
}

Dog::Dog(const Dog& other)
	:	Animal(), m_brain(new Brain())
{
	*m_brain = *other.m_brain;
	m_type = other.m_type;
	std::cout << GREEN;
	std::cout << "Dog copy contructor called" << std::endl;
	std::cout << RESET;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		*m_brain = *m_brain;
		m_type = other.m_type;
	}
	return (*this);
}

Dog::~Dog()
{
	delete m_brain;
	std::cout << RED;
	std::cout << "Dog destructor called" << std::endl;
	std::cout << RESET;
}

void	Dog::makeSound(void) const
{
	std::cout << m_type << " makes some sound: Wouaf !" << std::endl;
}

std::string	Dog::getType(void) const {return (m_type);}

void		Dog::printFirstIdea(void) const
{
	std::cout << m_type << " idea: " << m_brain->getIdeas()[0] << std::endl;
}