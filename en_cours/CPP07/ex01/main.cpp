#include "iter.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

void printStr(std::string value)
{
    std::cout << value << " ";
}

size_t printStrLen(std::string value)
{
    std::cout << value.length() << " ";
	return (value.length());
}

// template void emptify<std::string&>(T& a);
int main(void)
{
    std::string arr[] = {"Hi ", "I am ", "smart !"};
    std::size_t len = sizeof(arr) / sizeof(arr[0]);
    iter(arr, len, printStr);
    std::cout << std::endl;

    iter(arr, len, printStrLen);
    std::cout << std::endl;

    iter(arr, len, emptify<std::string&>);
    std::cout << std::endl;

    iter(arr, len, printStr);
    std::cout << std::endl;

    iter(arr, len, printStrLen);
    std::cout << std::endl;

    return (0);
}
