#include "abstract/APmergeMe.hpp"
#include "concrete/ListSorting.hpp"
#include "concrete/VectorSorting.hpp"
#include "concrete/MultisetSorting.hpp"
#include "numberSize.hpp"
#include <iostream>
#include <ctime>
#include <list>
#include <set>
#include <vector>

unsigned	*argvParsingToIntArray(int argc, char **argv)
{
	size_t		i;
	size_t		j;
	size_t		maxSize;
	long		number;
	unsigned	*unsignedArray;

	maxSize = getNumberOfDigits(UINT_MAX);
	unsignedArray = new unsigned[argc - 1];
	argv++;
	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!std::isdigit(argv[i][j]) || j + 1 > maxSize)
			{
				delete[] unsignedArray;
				return (NULL);
			}
			j++;
		}
		number = std::atoll(argv[i]);
		if (!(number >= 0 && number <= UINT_MAX))
		{
			delete[] unsignedArray;
			return (NULL);
		}
		unsignedArray[i] = static_cast<unsigned>(number);
		i++;
	}
	return (unsignedArray);
}

int	main(int argc, char **argv)
{
	APmergeMe	*listSorter;
	APmergeMe	*vectorSorter;
	APmergeMe	*multisetSorter;

	unsigned	iterations;
	size_t		size;
	unsigned	*tab;

	tab = argvParsingToIntArray(argc, argv);
	size = static_cast<size_t>(argc - 1);
	iterations = 2;

	listSorter = new ListSorting(tab, size);
	vectorSorter = new VectorSorting(tab, size);
	multisetSorter = new MultisetSorting(tab, size);

	std::cout << "===LIST TEST===" << std::endl;
	std::cout << "Before:	" << listSorter->getUnsignedArrayToStr() << std::endl;
	listSorter->sort();
	std::cout << "After:	" << listSorter->getSortedUnsignedArrayToStr() << std::endl;
	std::cout	<< "Time to process a range of " << size << " elements with std::list : "
				<< listSorter->repeatSort(iterations) << " us" << std::endl;

	std::cout << "===VECTOR TEST===" << std::endl;
	std::cout << "Before:	" << vectorSorter->getUnsignedArrayToStr() << std::endl;
	vectorSorter->sort();
	std::cout << "After:	" << vectorSorter->getSortedUnsignedArrayToStr() << std::endl;
	std::cout	<< "Time to process a range of " << size << " elements with std::vector : "
				<< vectorSorter->repeatSort(iterations) << " us" << std::endl;

	std::cout << "===MULTISET TEST===" << std::endl;
	std::cout << "Before:	" << multisetSorter->getUnsignedArrayToStr() << std::endl;
	multisetSorter->sort();
	std::cout << "After:	" << multisetSorter->getSortedUnsignedArrayToStr() << std::endl;
	std::cout	<< "Time to process a range of " << size << " elements with std::multiset : "
				<< multisetSorter->repeatSort(iterations) << " us" << std::endl;

	return (0);
}
