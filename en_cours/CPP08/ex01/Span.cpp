#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span()
	:	m_n(0),
		m_vec()
{}

Span::Span(unsigned n)
	:	m_n(n),
		m_vec()
{}

Span::Span(const Span& other)
	:	m_n(other.m_n),
		m_vec(other.m_vec)
{}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		m_n = other.m_n;
		m_vec = other.m_vec;
	}
	return (*this);
}

Span::~Span()
{}

void	Span::addNumber(int number)
{
	std::vector<int>::const_iterator pos;

	if (m_vec.size() == m_n)
		throw MaxCapacityReached();
	pos = std::lower_bound(m_vec.begin(), m_vec.end(), number);
	m_vec.insert(pos, number);
}

void	Span::addNumber(std::vector<int> vec)
{
	std::vector<int>::const_iterator pos;

	if (vec.size() + m_vec.size() > m_n)
		throw TooMuchElements();
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		pos = std::lower_bound(m_vec.begin(), m_vec.end(), *it);
		m_vec.insert(pos, *it);
	}
}

void	Span::addNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end)
{
	std::vector<int>::const_iterator pos;

	if (it_end - it_begin + m_vec.size() > m_n)
		throw TooMuchElements();
	for (std::vector<int>::iterator it = it_begin; it != it_end; it++)
	{
		pos = std::lower_bound(m_vec.begin(), m_vec.end(), *it);
		m_vec.insert(pos, *it);
	}
}

unsigned	Span::shortestSpan(void)
{
	int	sp;

	if (m_vec.size() < 2)
		throw NotEnoughElements();
	sp = m_vec[1] - m_vec [0];
	for (std::vector<int>::iterator it = m_vec.begin() + 1; it != m_vec.end(); it++)
		if (*it - *(it - 1) < sp)
			sp = *it - *(it - 1);
	return (static_cast<unsigned>(sp));
}

unsigned	Span::longestSpan(void)
{
	if (m_vec.size() < 2)
		throw NotEnoughElements();
	return (static_cast<unsigned>(m_vec.back() - m_vec.front()));
}

void	Span::display(void)
{
	for (std::vector<int>::iterator it = m_vec.begin(); it != m_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}