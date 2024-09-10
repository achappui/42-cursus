#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "../interface/IMateriaSource.hpp"
# include "../abstract_class/AMateria.hpp"
# include "../colors.hpp"

# define MATERIASOURCE_COLOR	DARK_TURQUOISE
# define STORAGE_SIZE			4
# define KNOWN_TYPES_SIZE		2
# define TYPE_0					"ice"
# define TYPE_1					"cure"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*m_storage[STORAGE_SIZE];
	bool		m_storageIsFull;
	long		m_lastLearnedIdx;
	std::string	m_knownTypes[KNOWN_TYPES_SIZE];
	bool	isInKnownTypes(const std::string type);
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource&	operator=(const MateriaSource& other);
	~MateriaSource();

	AMateria*	createMateria(const std::string& type);
	void		learnMateria(AMateria* materia);
};

#endif