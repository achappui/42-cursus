#ifndef CLAPTRAP_HPP
# define CLAPTRAC_HPP

# include <string>
# include "colors.hpp"

# define CLASS_COLOR	OLIVE

class ClapTrap
{
private:
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

	void	attack(const std::string& target);
	void	takeDamage(unsigned amount);
	void	beRepaired(unsigned amount);
};

#endif