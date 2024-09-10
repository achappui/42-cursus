#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Animal	*Animal[4];

	Animal[0] = new Cat();
	std::cout << std::endl;
	Animal[1] = new Dog();
	std::cout << "==============================================" << std::endl;

	Animal[0]->makeSound();
	((Cat *)Animal[0])->printFirstIdea();
	std::cout << std::endl;
	Animal[1]->makeSound();
	((Dog *)Animal[1])->printFirstIdea();

	std::cout << "==============================================" << std::endl;
	delete Animal[0];
	std::cout << std::endl;
	delete Animal[1];

	return 0;
}