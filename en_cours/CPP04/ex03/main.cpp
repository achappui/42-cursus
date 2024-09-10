#include <iostream>
#include "abstract_class/AMateria.hpp"
#include "concrete_class/Character.hpp"
#include "concrete_class/Cure.hpp"
#include "concrete_class/Ice.hpp"
#include "concrete_class/MateriaSource.hpp"

int	main(void)
{
	std::cout << "Creating material source:" << std::endl;
	IMateriaSource	*src = new MateriaSource();
	AMateria		*learningTab[6];

	for (unsigned i = 0; i < 6; i++)
	{
		if (i & 1)
			learningTab[i] = new Ice();
		else
			learningTab[i] = new Cure();
	}
	std::cout << "Feeding material source with learning material:" << std::endl;
	for (unsigned i = 0; i < 6; i++)
		src->learnMateria(learningTab[i]);
	std::cout << "Creating characters named Bob and javel:" << std::endl;
	ICharacter* bob = new Character("bob");
	ICharacter* javel = new Character("javel");
	std::cout << "Creating materias from the source:" << std::endl;
	AMateria* tmp1;
	AMateria* tmp2;
	tmp1 = src->createMateria("ice");
	tmp2 = src->createMateria("cure");
	std::cout << "Equiping the created materias:" << std::endl;
	bob->equip(tmp1);
	javel->equip(tmp2);
	std::cout << "Using them:" << std::endl;
	bob->use(0, *javel);
	javel->use(1, *bob);
	std::cout << "Freeing Bob and Javel: " << std::endl;
	delete bob;
	delete javel;
	std::cout << "Freeing tmp materias: " << std::endl;
	delete tmp1;
	delete tmp2;
	std::cout << "Freeing the source: " << std::endl;
	delete src;
	std::cout << "Freeing extra unused learning material: " << std::endl;
	for (unsigned i = 4; i < 6; i++)
		delete learningTab[i];
	return 0;
}