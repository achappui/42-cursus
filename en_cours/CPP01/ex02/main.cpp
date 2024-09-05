#include <iostream>
#include <string>
#include "colors.hpp"

int	main()
{
	std::string		stringVar = "HI THIS IS BRAIN";
	std::string		*stringPtr = &stringVar;
	std::string&	stringRef = stringVar;

	std::cout << OLIVE << "Addresses" << RESET << std::endl;
	std::cout << "stringVar address: " << &stringVar << std::endl;
	std::cout << "stringPtr address: " << &stringPtr << std::endl;
	std::cout << "stringRef address: " << &stringRef << std::endl;
	std::cout << OLIVE << "Values" << RESET << std::endl;
	std::cout << "stringVar value: " << stringVar << std::endl;
	std::cout << "stringPtr value: " << stringPtr << std::endl;
	std::cout << "stringRef value: " << stringRef << std::endl;
	std::cout << OLIVE << "Dereferencing stringPtr" << RESET << std::endl;
	std::cout << "stringPtr dereferenced value: " << *stringPtr << std::endl;
	std::cout << "stringPtr dereferenced address: " << &(*stringPtr) << std::endl;

	return (0);
}