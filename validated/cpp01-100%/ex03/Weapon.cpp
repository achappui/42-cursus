#include "Weapon.hpp"

Weapon::Weapon(const std::string type)
	:	m_type(type)
{

}

Weapon::Weapon(const Weapon& other)
	:	m_type(other.m_type)
{
	
}

Weapon&	Weapon::operator=(const Weapon& other)
{
	if (this != &other)
	{
		this->m_type = other.m_type;
	}
	return (*this);
}

Weapon::~Weapon() {}

const std::string&	Weapon::getType(void) const
{
	return (this->m_type);
}

void	Weapon::setType(const std::string type)
{
	this->m_type = type;
}