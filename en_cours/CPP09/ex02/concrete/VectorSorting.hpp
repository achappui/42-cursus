#ifndef VECTORSORTING_HPP
# define VECTORSORTING_HPP

# include "../abstract/APmergeMe.hpp"
# include <string>
# include <vector>

class VectorSorting : public APmergeMe
{
private:
	std::vector<unsigned>	m_sortedUnsignedArray;

	void							makeRestList(std::vector<unsigned>& arg, std::vector<unsigned>& restList);
	void							restInsertion(std::vector<unsigned>& arg, std::vector<unsigned>& restList);
	void							mergeInsert(std::vector<unsigned>& arg);
	std::vector<unsigned>::iterator	calculItToInsert(std::vector<unsigned>& restList, size_t trueIdxJcbNumber);

public:

	VectorSorting();
	VectorSorting(unsigned *unsignedArr, size_t size);
	VectorSorting(const VectorSorting& other);
	VectorSorting&	operator=(const VectorSorting& other);
	~VectorSorting();

	void		sort(void);
	std::string	getSortedUnsignedArrayToStr(void) const;

};

#endif
