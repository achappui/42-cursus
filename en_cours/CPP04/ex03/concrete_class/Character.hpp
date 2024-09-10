#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "../interface/ICharacter.hpp"
# include "../abstract_class/AMateria.hpp"
# include "../colors.hpp"

# define CHARACTER_COLOR	DARK_SALMON
# define INVENTORY_SIZE		4

class Character : public ICharacter
{
private:
	std::string	m_name;
	AMateria	*m_inventory[INVENTORY_SIZE];
	bool		m_inventoryIsFull;
public:
	Character();
	Character(const std::string name);
	Character(const Character& other);
	Character&	operator=(const Character& other);
	~Character();

	const std::string&	getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};

#endif