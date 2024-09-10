#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "../interface/ICharacter.hpp"
# include "../colors.hpp"

# define AMATERIA_COLOR	DARK_IVORY

class AMateria
{
protected:
	std::string	m_type;
public:
	AMateria();
	AMateria(const std::string& type);
	AMateria(const AMateria& other);
	AMateria&	operator=(const AMateria& other);
	virtual ~AMateria();

	const std::string&	getType(void) const;
	virtual void		use(ICharacter& target) = 0;
	virtual AMateria*	clone(void) const = 0;
};

# endif