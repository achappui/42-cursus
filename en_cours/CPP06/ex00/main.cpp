#include "AScalarConverter.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "You must give exactly 1 argument !" << std::endl;
		return (0);
	}
	std::string	input = argv[1];
	AScalarConverter::convert(input);
	return (0);
}
