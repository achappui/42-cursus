#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <ctime>
#include "argvParsing.hpp"
#include "uArray.hpp"

int	main(int argc, char **argv) //Faire un if qui empeche de mettre tant de nombres pour que jacobsthal fonctionne toujour
{

    uArray      arr;

    arr.size = 0;
    arr.array = NULL;

    if (argc == 1 || argc > 1000000)
    {
        std::cerr << "Invalid input" << std::endl;
        return (1);
    }
    else if (argc == 2)
    {
        if (parsingBySplitting(argv[1], arr) == -1)
        {
            std::cerr << "Invalid input" << std::endl;
            return (1);
        }
    }
    else
    {
        if (parsingByArgv(argc, argv, arr) == -1)
        {
            std::cerr << "Invalid input" << std::endl;
            return (1);
        }
    }

    try
    {
        PmergeMe    pmerge;
        pmerge.populate(arr);
        std::cout << "Jacobsthal numbers: " << std::endl;
        pmerge.displayJacobsthalNumbers();

        std::cout << "===List TEST===" << std::endl;
    	std::cout << "Before:	" << pmerge.listTreeToStr(pmerge.getListTree()) << std::endl;
    	pmerge.sortListTree();
    	std::cout << "After:	" << pmerge.listTreeToStr(pmerge.getSortedListTree()) << std::endl;
    	std::cout	<< "Time to process a range of " << arr.size << " elements with std::list : "
    				<< pmerge.sortFuncNtimes(&PmergeMe::sortListTree, 100) << " us" << std::endl;

    	// std::cout << "===VECTOR TEST===" << std::endl;
    	// std::cout << "Before:	" << pmerge.vectorTreeToStr(pmerge.getVectorTree()) << std::endl;
    	// pmerge.sortVectorTree();
    	// std::cout << "After:	" << pmerge.vectorTreeToStr(pmerge.getSortedVectorTree()) << std::endl;
    	// std::cout	<< "Time to process a range of " << arr.size << " elements with std::vector : "
    	// 			<< pmerge.sortFuncNtimes(&PmergeMe::sortVectorTree, 100) << " us" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception error !" << std::endl;
    }

    if (arr.array != NULL)
    {
        delete[] arr.array;
        arr.array = NULL;
    }
	return (0);
}
