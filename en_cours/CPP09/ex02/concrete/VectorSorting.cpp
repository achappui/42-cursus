#include "VectorSorting.hpp"
#include <sstream>
#include <algorithm>

VectorSorting::VectorSorting()
	:	APmergeMe(),
		m_sortedUnsignedArray()
{}

VectorSorting::VectorSorting(unsigned *unsignedArr, size_t size)
	:	APmergeMe(unsignedArr, size),
		m_sortedUnsignedArray()
{}

VectorSorting::VectorSorting(const VectorSorting& other)
	:	APmergeMe(other),
		m_sortedUnsignedArray(other.m_sortedUnsignedArray)
{}

VectorSorting&	VectorSorting::operator=(const VectorSorting& other)
{
	if (this != &other)
	{
		APmergeMe::operator=(other);
		m_sortedUnsignedArray = other.m_sortedUnsignedArray;
	}
	return (*this);
}

VectorSorting::~VectorSorting() {}

void	VectorSorting::sort(void)
{
	std::vector<unsigned>	arg;

	for (size_t i = 0; i < m_size; i++)
		arg.push_back(m_unsignedArray[i]);
	mergeInsert(arg);
	m_sortedUnsignedArray = arg;
}

void	VectorSorting::makeRestList(std::vector<unsigned>& arg, std::vector<unsigned>& restList)
{
	size_t	i1;
	size_t	i2;
	size_t	used;

	used = 0;
	if (arg.size() & 1)
		used++;
	i1 = 0;
	i2 = 1;
	while (arg.size() - used)
	{
		if (arg[i1] < arg[i2])
		{
			restList.push_back(arg[i1]);
			arg.erase(arg.begin() + i1);
			i1++;
			i2++;
		}
		else
		{
			restList.push_back(arg[i2]);
			arg.erase(arg.begin() + i2);
			i1++;
			i2++;
		}
		used++;
	}
}

void	VectorSorting::restInsertion(std::vector<unsigned>& arg, std::vector<unsigned>& restList)
{
	size_t							gone;
	size_t							idxJcb;
	std::vector<unsigned>::iterator	tmp;
	std::vector<unsigned>::iterator	itToInsert;

	gone = 0;
	idxJcb = 1;
	while (restList.size())
	{
		itToInsert = calculItToInsert(restList, jacobsthalGetN(++idxJcb) - 1 - gone);
		while (itToInsert != restList.begin())
		{
			tmp = itToInsert;
			tmp--;
			arg.insert(std::upper_bound(arg.begin(), arg.end(), *itToInsert), *itToInsert);
			restList.erase(itToInsert);
			itToInsert = tmp;
			gone++;
		}
		arg.insert(std::upper_bound(arg.begin(), arg.end(), *itToInsert), *itToInsert);
		restList.erase(itToInsert);
		gone++;
	}
}
#include <iostream>
void	VectorSorting::mergeInsert(std::vector<unsigned>& arg)
{
	std::vector<unsigned>	restList;
	unsigned				tmp;

	if (arg.size() < 2)
		return ;
	else if (arg.size() > 2)
	{
		makeRestList(arg, restList);
		mergeInsert(arg);
	}
	else
	{
		if (arg.front() > arg.back())
		{
			tmp = arg[0];
			arg[0] = arg[1];
			arg[1] = tmp;
		}
		return ;
	}
	restInsertion(arg, restList);
}

std::vector<unsigned>::iterator	VectorSorting::calculItToInsert(std::vector<unsigned>& restList, size_t trueIdxJcbNumber)
{
	std::vector<unsigned>::iterator	it;

	if (restList.size() == 0)
		return (restList.begin());
	it = restList.begin();
	while (trueIdxJcbNumber && it != restList.end())
	{
		it++;
		trueIdxJcbNumber--;
	}
	if (it == restList.end())
		it--;
	return (it);
}

std::string	VectorSorting::getSortedUnsignedArrayToStr(void) const
{
	std::stringstream	ss;
	std::string			str;

	for (std::vector<unsigned>::const_iterator it = m_sortedUnsignedArray.cbegin(); it != m_sortedUnsignedArray.cend(); it++)
		ss << *it << " ";
	str = ss.str();
	if (!str.empty() && str[str.size() - 1] == ' ')
		str.pop_back();
	return (str);
}
