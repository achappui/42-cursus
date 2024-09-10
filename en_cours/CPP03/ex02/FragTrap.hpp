#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define FRAGTRAP_COLOR	DARK_TEAL

class FragTrap : public ClapTrap
{
private:

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& other);
	FragTrap&	operator=(const FragTrap& other);
	~FragTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned amount);
	void	beRepaired(unsigned amount);
	void	highFivesGuys(void);
};

#endif