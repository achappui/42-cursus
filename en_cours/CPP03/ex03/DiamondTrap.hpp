#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# define DIAMONDTRAP	DARK_IVORY

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	m_name;
	unsigned	m_hitPoints;
	unsigned	m_energyPoints;
	unsigned	m_attackDamage;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap&	operator=(const DiamondTrap& other);
	~DiamondTrap();

	using ScavTrap::attack;
	using ScavTrap::takeDamage;
	using ScavTrap::beRepaired;

	void	whoAmI(void);
	void	displayAttributs(void);
};

#endif