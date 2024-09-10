#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	{
		ClapTrap	testClapTrap = ClapTrap("Susane");

		testClapTrap.attack("des briands");
		testClapTrap.beRepaired(2);
		testClapTrap.takeDamage(300);
	}
	{
		std::cout << "=================================================" << std::endl;
		ScavTrap	testScavTrap = ScavTrap("Heliotte");
		testScavTrap.attack("des kiwis");
		testScavTrap.beRepaired(8);
		testScavTrap.takeDamage(0.00000);
		testScavTrap.guardGate();
	}
	{
		std::cout << "=================================================" << std::endl;
		FragTrap	testScavTrap = FragTrap("Geser");
		testScavTrap.attack("une ruche");
		testScavTrap.beRepaired(700);
		testScavTrap.highFivesGuys();
		testScavTrap.takeDamage(8000);
		testScavTrap.highFivesGuys();
	}
	return (0);
}