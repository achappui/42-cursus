#include <iostream>
#include <cmath>
#include "colors.hpp"
#include "Fixed.hpp"
#include <stdio.h>

const int	Fixed::m_fracBitsNb = 8;

Fixed::Fixed() : m_rawBits(0)
{
	std::cout << GREEN;
	std::cout << "Default constructor called" << std::endl;
	std::cout << RESET;
}

Fixed::Fixed(const int i) : m_rawBits(i << 8)
{
	std::cout << GREEN;
	std::cout << "Int constructor called" << std::endl;
	std::cout << RESET;
}

Fixed::Fixed(const float f) : m_rawBits(roundf(f * 256.0f))
{
	std::cout << GREEN;
	std::cout << "Float constructor called" << std::endl;
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
	if (this != &other)
	{
		m_rawBits = other.m_rawBits;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}

Fixed::~Fixed()
{
	std::cout << RED;
	std::cout << "Destructor called" << std::endl;
	std::cout << RESET;
}

float	Fixed::toFloat(void) const
{
	return ((float)m_rawBits / 256.0f);
}

int		Fixed::toInt(void) const
{
	return (m_rawBits >> 8);
}

int		Fixed::getRawBits(void) const
{
	return (m_rawBits);
}

void	Fixed::setRawBits(const int rawBits)
{
	m_rawBits = rawBits;
}
