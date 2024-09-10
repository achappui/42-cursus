#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include "colors.hpp"

# define NB_OF_IDEAS	100

class Brain
{
private:
	std::string	m_ideas[NB_OF_IDEAS];
public:
	Brain();
	Brain(const Brain& other);
	Brain&	operator=(const Brain& other);
	~Brain();

	std::string	*getIdeas(void);
};

#endif