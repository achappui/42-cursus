#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include "colors.hpp"

class Dog : public Animal
{
private:
	Brain	*m_brain;

public:
	Dog();
	Dog(const Dog& other);
	Dog&	operator=(const Dog& other);
	~Dog();

	std::string	getType(void) const;
	void		makeSound(void) const;
	void		printFirstIdea(void) const;
};

#endif