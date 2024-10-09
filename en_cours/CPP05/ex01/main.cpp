#include <iostream>
#include "colors.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	arnold("Arnold", 1);
	Bureaucrat	gaspar("Gaspar", 150);
	Form		test_form("test form", 50, 1);

	std::cout << arnold << std::endl;
	std::cout << gaspar << std::endl;
	std::cout << test_form << std::endl;
	arnold.signForm(test_form);
	gaspar.signForm(test_form);
	std::cout << test_form << std::endl;

	try
	{
		Form	error_test("error_test", 151, 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << e.what() << std::endl;
		std::cerr << RESET;
	}

	try
	{
		Form	test("test", 150, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED;
		std::cerr << e.what() << std::endl;
		std::cerr << RESET;
	}
	
	return (0);
}