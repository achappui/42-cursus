#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include "colors.hpp"

class Cat : public Animal
{
private:
	Brain	*m_brain;

public:
	Cat();
	Cat(const Cat& other);
	Cat&	operator=(const Cat& other);
	~Cat();

	std::string	getType(void) const;
	void		makeSound(void) const;
	void		printFirstIdea(void) const;
};

#endif