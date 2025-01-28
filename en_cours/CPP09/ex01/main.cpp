#include "RPN.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Expecting exactly 1 argument !" << std::endl;
		return (1);
	}

	RPN	calculator;

	try
	{
		calculator.replaceInstructions(argv[1]);
	}
	catch (const RPN::InvalidInstructions& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	int	result;

	std::cout << "Instructions: ";
	calculator.displayInstructions();
	result = calculator.calculResult();
	std::cout << "Result: " << result << std::endl;

	return (0);
}