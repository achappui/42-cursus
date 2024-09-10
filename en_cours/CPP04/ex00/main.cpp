#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	{
		Animal* animalA = new Animal();

		animalA->makeSound();
		delete animalA;
	}
	std::cout << "==============================================" << std::endl;
	{
		Animal* animalB = new Cat();

		animalB->makeSound();
		delete animalB;
	}
	std::cout << "==============================================" << std::endl;
	{
		Animal* animalC = new Dog();

		animalC->makeSound();
		delete animalC;		
	}
	return 0;
}