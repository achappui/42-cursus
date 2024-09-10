#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define SCAVTRAP_COLOR	SALMON

class ScavTrap : public virtual ClapTrap
{
private:

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	ScavTrap&	operator=(const ScavTrap& other);
	virtual ~ScavTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned amount);
	void	beRepaired(unsigned amount);
	void	guardGate(void);
};

#endif