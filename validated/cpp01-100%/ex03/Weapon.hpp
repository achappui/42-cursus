#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
private:
	std::string	m_type;
public:
	Weapon(const std::string type);
	Weapon(const Weapon& other);
	Weapon&	operator=(const Weapon& other);
	~Weapon();

	const std::string&	getType(void) const;
	void				setType(const std::string type);
};



#endif