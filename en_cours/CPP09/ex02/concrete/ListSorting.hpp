#ifndef LISTSORTING_HPP
# define LISTSORTING_HPP

# include "../abstract/APmergeMe.hpp"
# include <string>
# include <list>

class ListSorting : public APmergeMe
{
private:
	std::list<unsigned>	m_sortedUnsignedArray;

	void							makeRestList(std::list<unsigned>& arg, std::list<unsigned>& restList);
	void							restInsertion(std::list<unsigned>& arg, std::list<unsigned>& restList);
	void							mergeInsert(std::list<unsigned>& arg);
	std::list<unsigned>::iterator	calculItToInsert(std::list<unsigned>& restList, size_t trueIdxJcbNumber);

public:

	ListSorting();
	ListSorting(unsigned *unsignedArr, size_t size);
	ListSorting(const ListSorting& other);
	ListSorting&	operator=(const ListSorting& other);
	~ListSorting();

	void		sort(void);
	std::string	getSortedUnsignedArrayToStr(void) const;

};

#endif
