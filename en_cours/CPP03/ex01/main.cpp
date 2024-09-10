#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	{
		ClapTrap	testClapTrap = ClapTrap("Susane");

		testClapTrap.attack("des briands");
		testClapTrap.beRepaired(2);
		testClapTrap.takeDamage(300);
	}
	{
		ScavTrap	testScavTrap = ScavTrap("Heliotte");
		testScavTrap.attack("des kiwis");
		testScavTrap.beRepaired(8);
		testScavTrap.takeDamage(0.00000);
		testScavTrap.guardGate();
	}
	return (0);
}