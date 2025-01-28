#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>

class Span
{
private:
	unsigned			m_n;
	std::vector<int>	m_vec;
public:
	class MaxCapacityReached : public std::exception {const char*	what() const throw() {return ("Max capacity reached !");}};
	class NotEnoughElements : public std::exception {const char*	what() const throw() {return ("Not enough elements !");}};
	class TooMuchElements : public std::exception {const char*	what() const throw() {return ("Too much elements to add !");}};

	Span();
	Span(unsigned n);
	Span(const Span& other);
	Span&	operator=(const Span& other);
	~Span();

	void		addNumber(int number);
	void		addNumber(std::vector<int> vec);
	void		addNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end);
	unsigned	shortestSpan(void);
	unsigned	longestSpan(void);
	void		display(void);
};

#endif