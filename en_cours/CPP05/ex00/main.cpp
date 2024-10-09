#include <iostream>
#include "colors.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	arnold("Arnold", 1);

	std::cout << arnold << std::endl;

	try
	{
		arnold.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << e.what() << std::endl;
		std::cerr << RESET;
	}

	std::cout << arnold << std::endl;
	arnold.decrementGrade();
	arnold.decrementGrade();
	std::cout << arnold << std::endl;
	arnold.incrementGrade();
	std::cout << arnold << std::endl;

	try
	{
		Bureaucrat	geser("Geser", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << e.what() << std::endl;
		std::cerr << RESET;
	}

	try
	{
		Bureaucrat	geser("Barder", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << e.what() << std::endl;
		std::cerr << RESET;
	}
	return (0);
}