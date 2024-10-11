#include "AScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <cmath>

int	AScalarConverter::findType(std::string str)
{
	size_t	size = str.length();
	if (size == 0)
		return (NONE);
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return (FLOAT);
	if (str == "nan" || str == "+inf" || str == "-inf")
		return (DOUBLE);
	if (size == 1 && !(str[0] >= '0' && str[0] <= '9'))
		return (CHAR);
	size_t	plusIndex = str.find_last_of('+');
	size_t	minusIndex = str.find_last_of('-');
	if ((plusIndex < std::string::npos && plusIndex > 0) || \
		(minusIndex < std::string::npos && minusIndex > 0))
		return (NONE);
	if (str.find_first_of('.') != str.find_last_of('.'))
		return (NONE);
	unsigned	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && \
			!(str[i] == '+') && \
			!(str[i] == '-') && \
			!(str[i] == '.') && \
			!(str[i] == 'f' && str.find_first_of('.') != std::string::npos && size > 2 && i == size - 1))
			return (NONE);
		i++;
	}
	if (str[size - 1] == 'f')
		return (FLOAT);
	else if (str.find_first_of('.') != std::string::npos)
		return (DOUBLE);
	return (INT);
}

void	AScalarConverter::fromChar(char c)
{
	std::cout << "char: " << visibleC(c) << std::endl << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl << "double: " << static_cast<double>(c) << std::endl;
}

void	AScalarConverter::fromInt(int i)
{
	if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
		std::cout << "char: " << "impossible" << std::endl;
	else
		std::cout << "char: " << visibleC(static_cast<char>(i)) << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl << "double: " << static_cast<double>(i) << std::endl;
}

void	AScalarConverter::fromFloat(float f)
{
	if (std::isinf(f) || std::isnan(f))
		std::cout << "char: " << "impossible" << std::endl << "int: " << "impossible" << std::endl;
	else
	{
		if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min())
			std::cout << "char: " << "impossible" << std::endl;
		else
			std::cout << "char: " << visibleC(static_cast<char>(f)) << std::endl;
		if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
			std::cout << "int: " << "impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	std::cout << "float: " << f << "f" << std::endl << "double: " << static_cast<double>(f) << std::endl;
}

void	AScalarConverter::fromDouble(double d)
{
	if (std::isinf(d) || std::isnan(d))
		std::cout << "char: " << "impossible" << std::endl << "int: " << "impossible" << std::endl;
	else
	{
		if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
			std::cout << "char: " << "impossible" << std::endl;
		else
			std::cout << "char: " << visibleC(static_cast<char>(d)) << std::endl;
		if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
			std::cout << "int: " << "impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

std::string	AScalarConverter::visibleC(char c)
{
	std::string	str;

	if (c <= 32 || c == 127)
		str = "Non displayable";
	else
		str = c;
	return (str);
}

void	AScalarConverter::convert(std::string str)
{
	int	type = findType(str);

	std::cout << std::fixed << std::showpoint << std::setprecision(1);
    try
	{
		switch (type)
		{
		case INT:
			fromInt(static_cast<int>(std::stoi(str)));
			break;
		case FLOAT:
			fromFloat(static_cast<float>(std::stof(str)));
			break;
		case DOUBLE:
			fromDouble(static_cast<double>(std::stod(str)));
			break;
		case CHAR:
			fromChar(static_cast<char>(str[0]));
			break;
		default:
			std::cout << "Invalid entry !" << std::endl;
			break;
		}
    }
	catch (const std::invalid_argument& e)
	{
        std::cout << e.what() << std::endl;
    }
	catch (const std::out_of_range& e)
	{
        std::cout << e.what() << std::endl;
    }
}

AScalarConverter::AScalarConverter()
{}

AScalarConverter::AScalarConverter(const AScalarConverter& other)
{
	(void)other;
}

AScalarConverter&	AScalarConverter::operator=(const AScalarConverter& other)
{
	(void)other;
	return (*this);
}
