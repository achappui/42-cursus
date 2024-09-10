#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "colors.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& other);
	Dog&	operator=(const Dog& other);
	~Dog();

	std::string	getType(void) const;
	void		makeSound(void) const;
};

#endif