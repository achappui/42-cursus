#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include "colors.hpp"

# define CLAPTRAP_COLOR	OLIVE

class ClapTrap
{
protected:
	std::string	m_name;
	unsigned	m_hitPoints;
	unsigned	m_energyPoints;
	unsigned	m_attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap&	operator=(const ClapTrap& other);
	~ClapTrap();

	virtual void	attack(const std::string& target);
	virtual void	takeDamage(unsigned amount);
	virtual void	beRepaired(unsigned amount);
};

#endif