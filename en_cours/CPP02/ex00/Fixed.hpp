#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	static const int	m_fracBitsNb; 
	int					m_rawBits;
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed&	operator=(const Fixed& other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(const int rawBits);
};


#endif