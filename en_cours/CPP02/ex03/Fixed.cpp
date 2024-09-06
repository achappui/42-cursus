#include <cmath>
#include "Fixed.hpp"

const int		Fixed::m_fracBitsNb = 8;
const float		Fixed::m_fracBitsDiff = 256.0f;
int				Fixed::getFracBitsNb(void) {return (m_fracBitsNb);}
float			Fixed::getFracBitsDiff(void) {return (m_fracBitsDiff);}
Fixed&			Fixed::min(Fixed& lhs, Fixed& rhs) {return (lhs < rhs ? lhs : rhs);}
const Fixed&	Fixed::min(const Fixed& lhs, const Fixed& rhs) {return (lhs < rhs ? lhs : rhs);}
Fixed&			Fixed::max(Fixed& lhs, Fixed& rhs) {return (lhs > rhs ? lhs : rhs);}
const Fixed&	Fixed::max(const Fixed& lhs, const Fixed& rhs) {return (lhs > rhs ? lhs : rhs);}

Fixed::Fixed() : m_rawBits(0) {}

Fixed::Fixed(const int i) : m_rawBits(i << m_fracBitsNb) {}

Fixed::Fixed(const float f) : m_rawBits(roundf(f * m_fracBitsDiff)) {}

Fixed::Fixed(const Fixed& other) : m_rawBits(other.m_rawBits) {}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		m_rawBits = other.m_rawBits;
	}
	return (*this);
}

Fixed&	Fixed::operator++()
{
	m_rawBits += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = *this;
	m_rawBits += 1;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	m_rawBits -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = *this;
	m_rawBits -= 1;
	return (tmp);
}

Fixed::~Fixed()
{

}

float	Fixed::toFloat(void) const {return ((float)m_rawBits / m_fracBitsDiff);}

int		Fixed::toInt(void) const {return (m_rawBits >> m_fracBitsNb);}

int		Fixed::getRawBits(void) const {return (m_rawBits);}

void	Fixed::setRawBits(const int rawBits) {m_rawBits = rawBits;}

std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}

bool	operator>(const Fixed& lhs, const Fixed& rhs) {return (lhs.getRawBits() > rhs.getRawBits());}
bool	operator<(const Fixed& lhs, const Fixed& rhs) {return (lhs.getRawBits() < rhs.getRawBits());}
bool	operator>=(const Fixed& lhs, const Fixed& rhs) {return (lhs.getRawBits() >= rhs.getRawBits());}
bool	operator<=(const Fixed& lhs, const Fixed& rhs) {return (lhs.getRawBits() <= rhs.getRawBits());}
bool	operator==(const Fixed& lhs, const Fixed& rhs) {return (lhs.getRawBits() == rhs.getRawBits());}
bool	operator!=(const Fixed& lhs, const Fixed& rhs) {return (lhs.getRawBits() != rhs.getRawBits());}


Fixed	operator+(const Fixed& lhs, const Fixed& rhs)
{
	Fixed	result;

	result.setRawBits(lhs.getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed	operator-(const Fixed& lhs, const Fixed& rhs)
{
	Fixed	result;

	result.setRawBits(lhs.getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed	operator*(const Fixed& lhs, const Fixed& rhs)
{
	Fixed	result;
	long	a;
	long	b;

	a = (long)lhs.getRawBits();
	b = (long)rhs.getRawBits();
	result.setRawBits((a * b)>> Fixed::getFracBitsNb());
	return (result);
}

Fixed	operator/(const Fixed& lhs, const Fixed& rhs)
{
	Fixed	result;
	long	a;
	long	b;

	a = (long)lhs.getRawBits() << Fixed::getFracBitsNb();
	b = (long)rhs.getRawBits();
	result.setRawBits(roundf(a / b));
	return (result);
}
