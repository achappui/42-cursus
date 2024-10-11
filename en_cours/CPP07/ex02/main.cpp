#include <iostream>
#include "colors.hpp"
#include "Array.hpp"

#define MAX_VAL 750

int main(void)
{
    Array<int> test(100);

	std::cout << SALMON;
	std::cout << "Testing operator[]: " << std::endl;
	std::cout << RESET;
	test[1] = 1;
	test[2] = 2;
	std::cout << test[2] << std::endl;
	std::cout << SALMON;
	std::cout << "Testing exception for test: " << std::endl;
	std::cout << RESET;
	try
    {
        test[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Array<int> testEmpty;
	std::cout << SALMON;
	std::cout << "Testing exception for testEmpty: " << std::endl;
	std::cout << RESET;
	try
    {
        testEmpty[0] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << SALMON;
	std::cout << "Testing size method: " << std::endl;
	std::cout << RESET;
	std::cout << "Size of test: " << test.size() << std::endl;
	std::cout << "Size of testEmpty: " << testEmpty.size() << std::endl;

	std::cout << SALMON;
	std::cout << "Testing copy constructor (for deep copy): " << std::endl;
	std::cout << RESET;
	Array<int> testCopy(test);

	std::cout << "Before modif test[1]: " << test[1] << std::endl;
	std::cout << "Before modif testCopy[1]: " << testCopy[1] << std::endl;
	std::cout << OLIVE;
	std::cout << "Modif testCopy[1]" << std::endl;
	std::cout << RESET;
	testCopy[1] = 3;
	std::cout << "After modif test[1]: " << test[1] << std::endl;
	std::cout << "After modif testCopy[1]: " << testCopy[1] << std::endl;

	std::cout << SALMON;
	std::cout << "Testing operator= (for deep copy and leaks): " << std::endl;
	std::cout << RESET;
	testCopy = test;
	std::cout << "Before modif test[1]: " << test[1] << std::endl;
	std::cout << "Before modif testCopy[1]: " << testCopy[1] << std::endl;
	std::cout << OLIVE;
	std::cout << "Modif testCopy[1]" << std::endl;
	std::cout << RESET;
	testCopy[1] = 8;
	std::cout << "After modif test[1]: " << test[1] << std::endl;
	std::cout << "After modif testCopy[1]: " << testCopy[1] << std::endl;

    return (0);
}
