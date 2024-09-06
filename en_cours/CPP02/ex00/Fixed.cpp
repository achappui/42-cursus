#include <iostream>
#include "colors.hpp"
#include "Fixed.hpp"

const int	m_fracBitsNb = 8;

Fixed::Fixed() : m_rawBits(0)
{
	std::cout << GREEN;
	std::cout << "Default constructor called" << std::endl;
	std::cout << RESET;
}

Fixed::Fixed(const Fixed& other) : m_rawBits(other.m_rawBits)
{
	std::cout << GREEN;
	std::cout << "Copy constructor called" << std::endl;
	std::cout << RESET;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment opperator called" << std::endl;
	if (this != &other)
	{
		m_rawBits = other.m_rawBits;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << RED;
	std::cout << "Destructor called" << std::endl;
	std::cout << RESET;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (m_rawBits);
}

void	Fixed::setRawBits(const int rawBits)
{
	std::cout << "setRawBits member function called" << std::endl;
	m_rawBits = rawBits;
}
