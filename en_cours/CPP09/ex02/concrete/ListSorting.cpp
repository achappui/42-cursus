#include "ListSorting.hpp"
#include <sstream>
#include <algorithm>
#include <iostream>

ListSorting::ListSorting()
	:	APmergeMe(),
		m_sortedUnsignedArray()
{}

ListSorting::ListSorting(unsigned *unsignedArr, size_t size)
	:	APmergeMe(unsignedArr, size),
		m_sortedUnsignedArray()
{}

ListSorting::ListSorting(const ListSorting& other)
	:	APmergeMe(other),
		m_sortedUnsignedArray(other.m_sortedUnsignedArray)
{}

ListSorting&	ListSorting::operator=(const ListSorting& other)
{
	if (this != &other)
	{
		APmergeMe::operator=(other);
		m_sortedUnsignedArray = other.m_sortedUnsignedArray;
	}
	return (*this);
}

ListSorting::~ListSorting() {}

void	ListSorting::sort(void)
{
	std::list<unsigned>	arg;

	for (size_t i = 0; i < m_size; i++)
		arg.push_back(m_unsignedArray[i]);
	mergeInsert(arg);
	m_sortedUnsignedArray = arg;
}

void	ListSorting::makeRestList(std::list<unsigned>& arg, std::list<unsigned>& restList)
{
	std::list<unsigned>::iterator	itArg1;
	std::list<unsigned>::iterator	itArg2;
	size_t							used;

	used = 0;
	if (arg.size() & 1)
		used++;
	itArg2 = arg.begin();
	itArg1 = arg.begin();
	while (arg.size() - used)
	{
		itArg2++;
		if (*itArg1 < *itArg2)
		{
			restList.splice(restList.end(), arg, itArg1);
			itArg2++;
			itArg1 = itArg2;
		}
		else
		{
			restList.splice(restList.end(), arg, itArg2);
			itArg1++;
			itArg2 = itArg1;
		}
		used++;
	}
}

std::list<unsigned>::iterator	ListSorting::calculItToInsert(std::list<unsigned>& restList, size_t trueIdxJcbNumber)
{
	std::list<unsigned>::iterator	it;

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

void	ListSorting::restInsertion(std::list<unsigned>& arg, std::list<unsigned>& restList)
{
	size_t							gone;
	size_t							idxJcb;
	std::list<unsigned>::iterator	tmp;
	std::list<unsigned>::iterator	itToInsert;

	gone = 0;
	idxJcb = 1;
	while (restList.size())
	{
		itToInsert = calculItToInsert(restList, jacobsthalGetN(++idxJcb) - 1 - gone);
		while (itToInsert != restList.begin())
		{
			tmp = itToInsert;
			tmp--;
			arg.splice(std::upper_bound(arg.begin(), arg.end(), *itToInsert), restList, itToInsert);
			itToInsert = tmp;
			gone++;
		}
		arg.splice(std::upper_bound(arg.begin(), arg.end(), *itToInsert), restList, itToInsert);
		gone++;
	}
}

void	ListSorting::mergeInsert(std::list<unsigned>& arg)
{
	std::list<unsigned>	restList;

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
			arg.splice(arg.end(), arg, arg.begin());
		return ;
	}
	restInsertion(arg, restList);
}

std::string	ListSorting::getSortedUnsignedArrayToStr(void) const
{
	std::stringstream	ss;
	std::string			str;

	for (std::list<unsigned>::const_iterator it = m_sortedUnsignedArray.cbegin(); it != m_sortedUnsignedArray.cend(); it++)
		ss << *it << " ";
	str = ss.str();
	if (!str.empty() && str[str.size() - 1] == ' ')
		str.pop_back();
	return (str);
}
