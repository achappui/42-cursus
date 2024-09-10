#ifndef ICE_HPP
# define ICE_HPP

# include "../abstract_class/AMateria.hpp"
# include "../colors.hpp"

# define ICE_COLOR	CYAN

class Ice : public AMateria
{
public:
	Ice();
	Ice(const std::string& type);
	Ice(const Ice& other);
	Ice&	operator=(const Ice& other);
	~Ice();

	void				use(ICharacter& target);
	Ice*				clone(void) const;
};

#endif