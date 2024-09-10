#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include "colors.hpp"

class Animal
{
protected:
	std::string	m_type;
public:
	Animal();
	Animal(const Animal& other);
	Animal&	operator=(const Animal& other);
	virtual ~Animal();

	std::string		getType(void) const;
	virtual void	makeSound(void) const = 0;
};

#endif