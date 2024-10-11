#ifndef ASCALARCONVERTER_HPP
# define ASCALARCONVERTER_HPP

# include <string>

enum literalType
{
	INT,
	FLOAT,
	DOUBLE,
	CHAR,
	NONE
};

class AScalarConverter
{
private:
	static int			findType(std::string str);
	static void			fromInt(int i);
	static void			fromChar(char c);
	static void			fromFloat(float f);
	static void			fromDouble(double d);
	static std::string	visibleC(char c);
public:
	static void	convert(std::string str);

	AScalarConverter();
	AScalarConverter(const AScalarConverter& other);
	AScalarConverter&	operator=(const AScalarConverter& other);
	virtual ~AScalarConverter() = 0;
};

#endif
