#include "ClapTrap.hpp"
#include <iostream>
int	main()
{
	ClapTrap	test = ClapTrap("Susane");
	ClapTrap	test_copy = ClapTrap(test);

	test.attack("des briands");
	test.takeDamage(4);
	test.attack("les brigands");
	test.beRepaired(2);
	test.takeDamage(300);

	test.beRepaired(2);
	test.takeDamage(1);
	test.attack("des briands");

	return (0);
}