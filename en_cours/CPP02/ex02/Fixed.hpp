#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	static const int	m_fracBitsNb;
	static const float	m_fracBitsDiff;
	int					m_rawBits;
public:
	static int			getFracBitsNb(void);
	static float		getFracBitsDiff(void);
	static Fixed&		min(Fixed& lhs, Fixed& rhs);
	static const Fixed&	min(const Fixed& lhs, const Fixed& rhs);
	static Fixed&		max(Fixed& lhs, Fixed& rhs);
	static const Fixed&	max(const Fixed& lhs, const Fixed& rhs);

	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed& other);
	Fixed&	operator=(const Fixed& other);
	Fixed&	operator++();
	Fixed	operator++(int); // Post
	Fixed&	operator--();
	Fixed	operator--(int); // Post
	~Fixed();

	float		toFloat(void) const;
	int			toInt(void) const;
	int			getRawBits(void) const;
	void		setRawBits(const int rawBits);
};

std::ostream&	operator<<(std::ostream& out, const Fixed& obj);

bool			operator>(const Fixed& lhs, const Fixed& rhs);
bool			operator<(const Fixed& lhs, const Fixed& rhs);
bool			operator>=(const Fixed& lhs, const Fixed& rhs);
bool			operator<=(const Fixed& lhs, const Fixed& rhs);
bool			operator==(const Fixed& lhs, const Fixed& rhs);
bool			operator!=(const Fixed& lhs, const Fixed& rhs);

Fixed			operator+(const Fixed& lhs, const Fixed& rhs);
Fixed			operator-(const Fixed& lhs, const Fixed& rhs);
Fixed			operator*(const Fixed& lhs, const Fixed& rhs);
Fixed			operator/(const Fixed& lhs, const Fixed& rhs);


#endif