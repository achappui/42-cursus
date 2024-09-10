#ifndef CURE_HPP
# define CURE_HPP

# include "../abstract_class/AMateria.hpp"
# include "../colors.hpp"

# define CURE_COLOR	TEAL

class Cure : public AMateria
{
public:
	Cure();
	Cure(const std::string& type);
	Cure(const Cure& other);
	Cure&	operator=(const Cure& other);
	~Cure();

	void				use(ICharacter& target);
	Cure*				clone(void) const;
};

#endif