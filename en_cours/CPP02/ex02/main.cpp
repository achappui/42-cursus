#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	Fixed		c(2);
	Fixed const d(10);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << c + d << std::endl;
	std::cout << c - d << std::endl;
	std::cout << c / d << std::endl;
	std::cout << d / c << std::endl;
	std::cout << c * d << std::endl; //checker division par 0

	return (0);
}
