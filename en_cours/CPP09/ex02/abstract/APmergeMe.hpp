#ifndef APMERGEME_HPP
# define APMERGEME_HPP

# include <string>
# include <list>
# include <set>
# include <vector>

class APmergeMe
{
private:
	size_t	jacobsthalCalculN(size_t n);
	size_t	*jacobsthalCalculAll(void);

protected:
	const size_t	*m_jacobSthalNumbers;
	const size_t	m_jacobSthalSize;
	unsigned		*m_unsignedArray;
	size_t			m_size;

public:
	class NoUnsignedArray : std::exception {public: const char *what() const throw() {return ("Unsigned array is NULL !");}};
	class ParsingFailed : std::exception {public: const char *what() const throw() {return ("Parsing failed !");}};
	class BadJacobsthalIndex : std::exception {public: const char *what() const throw() {return ("Jacobsthal index too big !");}};
	class IndexOutOfRange : std::exception {public: const char *what() const throw() {return ("Index out of range !");}};

	APmergeMe();
	APmergeMe(unsigned *unsignedArr, size_t size);
	APmergeMe(const APmergeMe& other);
	APmergeMe&	operator=(const APmergeMe& other);
	virtual	~APmergeMe();

	virtual void		sort(void) = 0;
			double		repeatSort(unsigned nb);
			std::string	getUnsignedArrayToStr(void) const;
	virtual	std::string	getSortedUnsignedArrayToStr(void) const = 0;
			size_t		jacobsthalGetN(size_t n);
};

#endif
