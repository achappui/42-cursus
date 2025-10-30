#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <list>
# include "uArray.hpp"

# define JACOBSTHAL_SIZE    32

typedef std::vector<std::vector<unsigned> > t_vtree;
typedef std::vector<unsigned>				t_vbranch;
typedef std::list<std::list<unsigned> >     t_ltree;
typedef std::list<unsigned>				    t_lbranch;

class PmergeMe
{
private:
    static size_t	calculRank(size_t n);

    const unsigned*         m_jacobSthalNumbers;

    t_ltree                 m_listTree;
    t_vtree                 m_vectorTree;
    t_ltree                 m_sortedListTree;
    t_vtree                 m_sortedVectorTree;

    void        makeVtree(t_vtree &tree, t_vtree &restTree);
    void        resolveVtree(t_vtree &tree, t_vtree &restTree);
    void        binaryInsertVtree(t_vtree &tree, t_vbranch what, size_t size);

    void        makeLtree(t_ltree &tree, t_ltree &restTree);
    void        resolveLtree(t_ltree &tree, t_ltree &restTree);
    void        binaryInsertLtree(t_ltree &tree, t_lbranch what, size_t size);

    unsigned    jacobsthalGetN(size_t n);
	unsigned    jacobsthalCalculN(size_t n);
	unsigned*   jacobsthalCalculAll();

public:
	class BadJacobsthalIndex : std::exception {public: const char *what() const throw() {return ("Jacobsthal index too big !");}};
	class IndexOutOfRange : std::exception {public: const char *what() const throw() {return ("Index out of range !");}};

	static std::string  listTreeToStr(t_ltree ltree);
	static std::string  vectorTreeToStr(t_vtree vtree);

	PmergeMe();
	PmergeMe(uArray& array);
	PmergeMe(const PmergeMe& other);
	PmergeMe&	operator=(const PmergeMe& other);
	~PmergeMe();

	void    populate(uArray& array);
	void    displayJacobsthalNumbers();

	void    sortVectorTree();
	void    sortListTree();

	double  sortFuncNtimes(void (PmergeMe::*sortFunc)(), size_t n);

	t_vtree getSortedVectorTree() const;
	t_vtree getVectorTree() const;
	t_ltree getSortedListTree() const;
	t_ltree getListTree() const;
};

#endif
