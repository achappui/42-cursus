#include "APmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>

//non-static
APmergeMe::APmergeMe()
	:	m_jacobSthalNumbers(jacobsthalCalculAll()),
		m_jacobSthalSize(sizeof(size_t) * 8),
		m_unsignedArray(NULL),
		m_size(0)
{}

APmergeMe::APmergeMe(unsigned *unsignedArr, size_t size)
	:	m_jacobSthalNumbers(jacobsthalCalculAll()),
		m_jacobSthalSize(sizeof(size_t) * 8),
		m_unsignedArray(unsignedArr),
		m_size(size)
{}

APmergeMe::APmergeMe(const APmergeMe& other)
	:	m_jacobSthalNumbers(jacobsthalCalculAll()),
		m_jacobSthalSize(sizeof(size_t) * 8),
		m_unsignedArray(other.m_unsignedArray),
		m_size(other.m_size)
{}

APmergeMe&	APmergeMe::operator=(const APmergeMe& other)
{
	if (this != &other)
	{
		m_unsignedArray = other.m_unsignedArray;
		m_size = other.m_size;
	}
	return (*this);
}

APmergeMe::~APmergeMe() {delete[] m_jacobSthalNumbers;}

double APmergeMe::repeatSort(unsigned nb)
{
	clock_t startTime = clock();
	for (unsigned i = 0; i < nb; i++)
		sort();
	clock_t endTime = clock();

	return (static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC / nb * 1e6); 
}


std::string	APmergeMe::getUnsignedArrayToStr(void) const
{
	std::stringstream	ss;
	std::string			str;

	for (size_t i = 0; i < m_size; i++)
		ss << m_unsignedArray[i] << " ";
	str = ss.str();
	if (!str.empty() && str[str.size() - 1] == ' ')
		str.pop_back();
	return (str);
}

size_t	APmergeMe::jacobsthalGetN(size_t n)
{
	if (n >= m_jacobSthalSize)
		throw IndexOutOfRange();
	return (m_jacobSthalNumbers[n]);
}

size_t	APmergeMe::jacobsthalCalculN(size_t n)
{
	size_t	result;

	if (n >= sizeof(size_t) * 8)
		throw BadJacobsthalIndex();
	if (n & 1)
		result = (static_cast<size_t>(pow(2, n)) + 1) / 3;
	else
		result = (static_cast<size_t>(pow(2, n)) - 1) / 3;
	return (result);
}

size_t	*APmergeMe::jacobsthalCalculAll(void)
{
	size_t	*jacobSthalNumbers;
	jacobSthalNumbers = new size_t[sizeof(size_t) * 8];
	for (size_t i = 0; i < sizeof(size_t) * 8; i++)
		jacobSthalNumbers[i] = jacobsthalCalculN(i);
	return (jacobSthalNumbers);
}
