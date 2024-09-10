#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	for (unsigned i = 0; i < NB_OF_IDEAS; i++)
		m_ideas[i] = "Empty";
	std::cout << GREEN;
	std::cout << "Brain contructor called" << std::endl;
	std::cout << RESET;
}

Brain::Brain(const Brain& other)
{
	for (unsigned i = 0; i < NB_OF_IDEAS; i++)
		m_ideas[i] = other.m_ideas[i];
	std::cout << GREEN;
	std::cout << "Brain copy contructor called" << std::endl;
	std::cout << RESET;
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (unsigned i = 0; i < NB_OF_IDEAS; i++)
			m_ideas[i] = other.m_ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << RED;
	std::cout << "Brain destructor called" << std::endl;
	std::cout << RESET;
}

std::string	*Brain::getIdeas(void) {return (m_ideas);}