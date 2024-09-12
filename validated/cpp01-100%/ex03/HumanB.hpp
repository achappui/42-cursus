#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string	m_name;
	Weapon		*m_weapon;
public:
	HumanB(const std::string name);
	HumanB(const HumanB& other);
	~HumanB();

	void	attack(void);
	void	setWeapon(Weapon& weapon);
};


#endif
