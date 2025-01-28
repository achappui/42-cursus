#include "MultisetSorting.hpp"
#include <sstream>

MultisetSorting::MultisetSorting()
	:	APmergeMe(),
		m_sortedUnsignedArray()
{}

MultisetSorting::MultisetSorting(unsigned *unsignedArr, size_t size)
	:	APmergeMe(unsignedArr, size),
		m_sortedUnsignedArray()
{}

MultisetSorting::MultisetSorting(const MultisetSorting& other)
	:	APmergeMe(other),
		m_sortedUnsignedArray(other.m_sortedUnsignedArray)
{}

MultisetSorting&	MultisetSorting::operator=(const MultisetSorting& other)
{
	if (this != &other)
	{
		APmergeMe::operator=(other);
		m_sortedUnsignedArray = other.m_sortedUnsignedArray;
	}
	return (*this);
}

MultisetSorting::~MultisetSorting() {}

void	MultisetSorting::sort(void)
{
	m_sortedUnsignedArray.clear();
	for (size_t i = 0; i < m_size; i++)
		m_sortedUnsignedArray.insert(m_unsignedArray[i]);
}

std::string	MultisetSorting::getSortedUnsignedArrayToStr(void) const
{
	std::stringstream	ss;
	std::string			str;

	for (std::multiset<unsigned>::const_iterator it = m_sortedUnsignedArray.cbegin(); it != m_sortedUnsignedArray.cend(); it++)
		ss << *it << " ";
	str = ss.str();
	if (!str.empty() && str[str.size() - 1] == ' ')
		str.pop_back();
	return (str);
}
