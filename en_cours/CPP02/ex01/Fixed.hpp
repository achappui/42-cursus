#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	static const int	m_fracBitsNb; 
	int					m_rawBits;
public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed& other);
	Fixed&	operator=(const Fixed& other);
	~Fixed();

	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(const int rawBits);
};

std::ostream&	operator<<(std::ostream& out, const Fixed& obj);


#endif