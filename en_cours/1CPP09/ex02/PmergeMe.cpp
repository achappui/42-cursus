#include "PmergeMe.hpp"
#include "uArray.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>

PmergeMe::PmergeMe()
    :   m_jacobSthalNumbers(NULL),
        m_listTree(),
        m_vectorTree()
{
    m_jacobSthalNumbers = jacobsthalCalculAll();
}

PmergeMe::PmergeMe(uArray& array)
:   m_jacobSthalNumbers(NULL),
    m_listTree(),
    m_vectorTree()
{
    m_jacobSthalNumbers = jacobsthalCalculAll();
    populate(array);
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    m_jacobSthalNumbers = jacobsthalCalculAll();
    m_listTree = other.m_listTree;
    m_vectorTree = other.m_vectorTree;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
        m_listTree = other.m_listTree;
        m_vectorTree = other.m_vectorTree;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
    delete[] m_jacobSthalNumbers;
}




//PUBLIC
std::string PmergeMe::listTreeToStr(t_ltree ltree)
{
	std::stringstream	ss;
	std::string			str;

	for (t_ltree::const_iterator it = ltree.begin(); it != ltree.end(); it++)
		ss << (*it).front() << " ";
	str = ss.str();
	if (!str.empty() && str[str.size() - 1] == ' ')
		str.resize(str.size() - 1);
	return (str);
}

std::string	PmergeMe::vectorTreeToStr(t_vtree vtree)
{
	std::stringstream	ss;
	std::string			str;

	for (t_vtree::const_iterator it = vtree.begin(); it != vtree.end(); it++)
		ss << (*it).front() << " ";
	str = ss.str();
	if (!str.empty() && str[str.size() - 1] == ' ')
		str.resize(str.size() - 1);
	return (str);
}

void    PmergeMe::populate(uArray& array)
{
    t_vbranch   tmpv(1);
    t_lbranch   tmpl(1);

    m_vectorTree.clear();
    m_listTree.clear();
    for (size_t i = 0; i < array.size; i++)
    {
        tmpv.front() = array.array[i];
        tmpl.front() = array.array[i];
        m_vectorTree.push_back(tmpv);
		m_listTree.push_back(tmpl);
    }

}

size_t	PmergeMe::calculRank(size_t n)
{
	size_t	rank = 0;

	while (n > 1)
	{
		n >>= 1;
		rank++;
	}
	return (rank);
}

void    PmergeMe::makeVtree(t_vtree &tree, t_vtree &restTree)
{
    size_t    i = 0;
    size_t    half = 0;

    if (tree.size() < 2)
        return ;
    //Make the tree
    while (tree.size() > 1)
    {
        i = 0;
        if (tree.size() & 1)
            restTree.push_back(tree[tree.size() - 1]);
        half = tree.size() >> 1;
        while(i < half)
        {
            if (tree[i][0] > tree[i + half][0])
                tree[i].insert(tree[i].end(), tree[i + half].begin(), tree[i + half].end());
            else
                tree[i].insert(tree[i].begin(), tree[i + half].begin(), tree[i + half].end());
            i++;
        }
        tree.resize(tree.size() >> 1);
    }
}

void	PmergeMe::resolveVtree(t_vtree &tree, t_vtree &restTree)
{
	size_t	i = 2;
	size_t	j = jacobsthalGetN(i);
	size_t	rank = calculRank(tree[0].size());
	bool	jacobLastTurn = 0;

	while (rank > 0)
	{
		i = 2;
		j = jacobsthalGetN(i);
		jacobLastTurn = 0;
		while (1)
		{
			//Insert element if IT IS NOT an already inserted one at this rank
			if (calculRank(tree[j - 1].size()) == rank)
			{
			    binaryInsertVtree(tree, restTree, j - 1, REST_OFF);
				j++;
			}
			if (j == jacobsthalGetN(i - 1))
			{
				//Update de jacobsthal index for backward insertion
				j = jacobsthalGetN(++i);
				if (j > tree.size())
				{
					if (jacobLastTurn)
						break ;
					jacobLastTurn = 1;
					//Insert rest if any
					if (restTree.size() && calculRank(restTree[restTree.size() - 1].size()) == rank - 1)
					    binaryInsertVtree(tree, restTree, tree.size(), REST_ON);
					j = tree.size();
				}
			}
			else
			    j--;
		}
		rank--;
	}
}

void    PmergeMe::binaryInsertVtree(t_vtree &tree, t_vtree &restTree, size_t pos, bool mode)
{
    size_t      downBoard = 0;
    size_t      upBoard = pos;
	size_t      mid = downBoard + ((upBoard - downBoard) >> 1);
	t_vbranch   what;

	if (mode == REST_ON)
	{
	    what = restTree[restTree.size() - 1];
		restTree.resize(restTree.size() - 1);
	}
	else
	{
	    what.insert(what.begin(), tree[pos].begin() + (tree[pos].size() >> 1), tree[pos].end());
	    tree[pos].resize(tree[pos].size() >> 1);
	}

	if (pos == 0)
		tree.insert(tree.begin(), what);
	else if (what[0] >= tree[upBoard - 1][0])
	    tree.insert(tree.begin() + upBoard, what);
	else if (what[0] <= tree[downBoard][0])
	    tree.insert(tree.begin(), what);
	else
    {
    	while (upBoard - downBoard > 1)
    	{

    		if (what[0] > tree[mid][0])
                downBoard = mid;
    		else
    			upBoard = mid;
    		mid = downBoard + ((upBoard - downBoard) >> 1);
    	}
        tree.insert(tree.begin() + upBoard, what);
    }
}

void   PmergeMe::sortVectorTree()
{
    t_vtree     vtree;
    t_vtree     rests;

    vtree = m_vectorTree;
    makeVtree(vtree, rests);
    resolveVtree(vtree, rests);
    m_sortedVectorTree = vtree;
}

void    PmergeMe::makeLtree(t_ltree &tree, t_ltree &restTree)
{
    t_ltree::iterator   itStart;
    t_ltree::iterator   itEnd;

    if (tree.size() < 2)
        return ;
    //Make the tree
    while (tree.size() > 1)
    {
        itEnd = tree.end();
        if (tree.size() & 1)
        {
            restTree.push_back(tree.back());
            itEnd--;
        }
        itStart = tree.begin();
        while(itStart != itEnd)
        {
            itEnd--;
            if ((*itStart).front() > (*itEnd).front())
                (*itStart).splice((*itStart).end(), (*itEnd), (*itEnd).begin(), (*itEnd).end());
            else
                (*itStart).splice((*itStart).begin(), (*itEnd), (*itEnd).begin(), (*itEnd).end());
            itStart++;
        }
        tree.resize(tree.size() >> 1);
    }
}

void	PmergeMe::resolveLtree(t_ltree &tree, t_ltree &restTree)
{
	size_t	i = 2;
	size_t	j = jacobsthalGetN(i);
	size_t	rank = calculRank(tree.front().size());
	bool	jacobLastTurn = 0;

	while (rank > 0)
	{
		i = 2;
		j = jacobsthalGetN(i);
		jacobLastTurn = 0;
		while (1)
		{
			//Insert element if IT IS NOT an already inserted one at this rank
			if (calculRank((*lTreeAtN(tree.begin(), j - 1, TO_RIGHT)).size()) == rank)
			{
			    binaryInsertLtree(tree, restTree, j - 1, REST_OFF);
				j++;
			}
			if (j == jacobsthalGetN(i - 1))
			{
				//Update de jacobsthal index for backward insertion
				j = jacobsthalGetN(++i);
				if (j > tree.size())
				{
					if (jacobLastTurn)
						break ;
					jacobLastTurn = 1;
					//Insert rest if any
					if (restTree.size() && calculRank(restTree.back().size()) == rank - 1)
					    binaryInsertLtree(tree, restTree, tree.size(), REST_ON);
					j = tree.size();
				}
			}
			else
			    j--;
		}
		rank--;
	}
}

t_ltree::iterator	PmergeMe::lTreeAtN(t_ltree::iterator startIdx, size_t n, bool mode)
{
	if (mode == TO_LEFT)
		while (n-- > 0)
			startIdx--;
	else
		while (n-- > 0)
			startIdx++;
	return (startIdx);
}

t_lbranch::iterator	PmergeMe::lBranchAtN(t_lbranch::iterator startIdx, size_t n, bool mode)
{
	if (mode == TO_LEFT)
		while (n-- > 0)
			startIdx--;
	else
		while (n-- > 0)
			startIdx++;
	return (startIdx);
}

void    PmergeMe::binaryInsertLtree(t_ltree &tree, t_ltree &restTree, size_t pos, bool mode)
{
    size_t				downBoard = 0;
    size_t				upBoard = pos;
	size_t				mid = downBoard + ((upBoard - downBoard) >> 1);
	t_ltree				what(1);
	t_ltree::iterator	itPos = lTreeAtN(tree.begin(), pos, TO_RIGHT);
	t_ltree::iterator	it;

	if (mode == REST_ON)
	{
		what.front().splice(what.front().begin(), restTree.back(), restTree.back().begin(), restTree.back().end());
		restTree.resize(restTree.size() - 1);
	}
	else
		what.front().splice(what.front().begin(), (*itPos), lBranchAtN((*itPos).begin(), (*itPos).size() >> 1, TO_RIGHT), (*itPos).end());

	if (pos == 0)
	    tree.splice(tree.begin(), what);
	else if (what.front().front() >= tree.back().front())
	    tree.splice(tree.end(), what);
	else if (what.front().front() <= tree.front().front())
	    tree.splice(tree.begin(), what);
	else
    {
		it = lTreeAtN(tree.begin(), mid, TO_RIGHT);
    	while (upBoard - downBoard > 1)
    	{
    		if (what.front().front() > (*it).front())
			{
                downBoard = mid;
				it = lTreeAtN(it, (upBoard - downBoard) >> 1, TO_RIGHT);
			}
    		else
			{
    			upBoard = mid;
				it = lTreeAtN(it, (upBoard - downBoard) >> 1, TO_LEFT);
				if ((upBoard - downBoard) & 1)
				    it--;
			}
    		mid = downBoard + ((upBoard - downBoard) >> 1);
    	}
        if (mid != upBoard)
            it++;
        tree.splice(it, what);
    }
}

void   PmergeMe::sortListTree()
{
    t_ltree     ltree;
    t_ltree     rests;

    ltree = m_listTree;
    makeLtree(ltree, rests);
    resolveLtree(ltree, rests);
    m_sortedListTree = ltree;
}

double  PmergeMe::sortFuncNtimes(void (PmergeMe::*sortFunc)(), size_t n)
{
    clock_t startTime = clock();
	for (size_t i = 0; i < n; i++)
		(this->*sortFunc)();
	clock_t endTime = clock();

	return (static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC / n * 1e6);
}

unsigned	PmergeMe::jacobsthalGetN(size_t n)
{
	if (n >= JACOBSTHAL_SIZE)
		throw IndexOutOfRange();
	return (m_jacobSthalNumbers[n]);
}

unsigned	PmergeMe::jacobsthalCalculN(size_t n)
{
	size_t	result;

	if (n >= sizeof(size_t) * 8)
		throw BadJacobsthalIndex();
	if (n & 1)
		result = ((1 << n) + 1) / 3;
	else
		result = ((1 << n) - 1) / 3;
	return (result);
}

unsigned	*PmergeMe::jacobsthalCalculAll()
{
	unsigned	*jacobSthalNumbers;

	jacobSthalNumbers = new unsigned[JACOBSTHAL_SIZE];
	for (unsigned i = 0; i < JACOBSTHAL_SIZE; i++)
		jacobSthalNumbers[i] = jacobsthalCalculN(i);
	return (jacobSthalNumbers);
}

void    PmergeMe::displayJacobsthalNumbers()
{
    for (size_t i = 0; i < JACOBSTHAL_SIZE; i++)
        std::cout << m_jacobSthalNumbers[i] << " ";
    std::cout << std::endl;
}


t_vtree PmergeMe::getSortedVectorTree() const {return (m_sortedVectorTree);}
t_vtree PmergeMe::getVectorTree() const {return (m_vectorTree);}
t_ltree PmergeMe::getSortedListTree() const {return (m_sortedListTree);}
t_ltree PmergeMe::getListTree() const {return (m_listTree);}
