#ifndef MULTISETSORTING_HPP
# define MULTISETSORTING_HPP

# include "../abstract/APmergeMe.hpp"
# include <string>
# include <set>

class MultisetSorting : public APmergeMe
{
private:
	std::multiset<unsigned>	m_sortedUnsignedArray;

public:

	MultisetSorting();
	MultisetSorting(unsigned *unsignedArr, size_t size);
	MultisetSorting(const MultisetSorting& other);
	MultisetSorting&	operator=(const MultisetSorting& other);
	~MultisetSorting();

	void		sort(void);
	std::string	getSortedUnsignedArrayToStr(void) const;

};

#endif
