#include "Span.hpp"
#include <iostream>
#include <random>
#include <algorithm>

void	displayVector(std::vector<int> vec)
{
	std::cout << "Vector size: " << vec.size() << std::endl;
	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

std::vector<int>	randomVector10k(unsigned size)
{
	std::vector<int>				vec;
	std::random_device				rd;
	std::mt19937 					gen(rd());
	std::uniform_int_distribution<>	dis(-10000, 10000);

    for (unsigned i = 0; i < size; ++i)
        vec.push_back(dis(gen));
	return (vec);
}

int main()
{
	Span 				sp;
	std::vector<int>	vec = randomVector10k(100);

	std::cout << "TEST WITH 10K ELEMENTS" << std::endl;
	sp = Span(10000);
	sp.addNumber(vec.begin(), vec.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "Check longestSpan: " << *std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(), vec.end()) << std::endl;

	std::cout << "TEST FROM SUBJECT" << std::endl;
	sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.display();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "TEST EXCEPTIONS" << std::endl;
	sp = Span();
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		sp.addNumber(54645);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	sp = Span(2);
	try
	{
		sp.addNumber({1, 2, 3, 4, 5});
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		sp.addNumber(vec.begin(), vec.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}