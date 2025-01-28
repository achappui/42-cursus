#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
    const int							arr[] = {10, 20, 30, 40, 50, 60};
    const std::vector<int>				vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	int									valueToFind;
	std::vector<int>::const_iterator	it;

	valueToFind = 60;
	it = easyfind(vec, valueToFind);

    if (it != vec.end())
        std::cout << "Found " << *it << " at position " << std::distance(vec.begin(), it) << std::endl;
    else 
        std::cout << "Value " << valueToFind << " not found in the vector." << std::endl;

	valueToFind = 535;
	it = easyfind(vec, valueToFind);

    if (it != vec.end())
        std::cout << "Found " << *it << " at position " << std::distance(vec.begin(), it) << std::endl;
    else 
        std::cout << "Value " << valueToFind << " not found in the vector." << std::endl;

	return (0);
}
