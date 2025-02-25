#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <map>
#include "Date.hpp"

BitcoinExchange::BitcoinExchange()
	:	m_database()
{}

BitcoinExchange::BitcoinExchange(std::string databasePath)
	:	m_database()
{
	loadDatabase(databasePath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	:	m_database(other.m_database)
{}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		m_database = other.m_database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

void	BitcoinExchange::loadDatabase(std::string databasePath)
{
	std::ifstream	file;
	std::string		line;

	file.open(databasePath.c_str());
	if (!file.is_open())
		throw FileOpenError();
	m_database.clear();
	std::getline(file, line); //To get rid of first row
	while (std::getline(file, line))
	{
		validateLine(line, ",");
		m_database[extractDateFromLine(line, ",")] = extractValueFromLine(line, ",");
	}
	file.close();
}

void	BitcoinExchange::displayValuesFromFile(std::string filePath)
{
	std::ifstream	file;
	std::string		line;
	Date			date;
	float			value;

	if (m_database.empty())
		throw EmptyDatabase();
	file.open(filePath.c_str());
	if (!file.is_open())
		throw FileOpenError();

	std::getline(file, line);  //To get rid of first row
	while (std::getline(file, line))
	{
		try
		{
			validateLine(line, " | ");
			if (line.find_first_of(".") == std::string::npos && (extractValueFromLine))
			{
				int	intValue = std::stoi(line.substr(13));
				if (!(intValue >= 0 && intValue <= 1000))
				throw InvalidValue();
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << " => " << line << std::endl;
			continue ;
		}
		date = extractDateFromLine(line, " | ");
		value = extractValueFromLine(line, " | ");
		std::cout << date << " => " << value << " = " << value * findExchangeRate(date) << std::endl;
	}
}

//private
Date	BitcoinExchange::extractDateFromLine(std::string line, std::string separator)
{
	Date	date(line.substr(0, line.find(separator)));

	return (date);
}

float	BitcoinExchange::extractValueFromLine(std::string line, std::string separator)
{
	float	value;

	value = std::stof(line.substr(line.find(separator) + separator.length()));
	return (value);
}

void	BitcoinExchange::validateLine(std::string line, std::string separator)
{
	std::string	value;
	float		testFloat;
	int			testInt;
	bool		isFloat;
	size_t		i;

	try
	{
		Date::validateDateFormat(line.substr(0, 10));
	}
	catch(const std::exception& e)
	{
		throw InvalidLine();
	}
	if (line.substr(10, separator.size()).compare(separator) != 0)
		throw InvalidLine();
	Date::validateDate(extractDateFromLine(line, separator));
	value = line.substr(10 + separator.size());
	if (value.find_first_of('.') != value.find_last_of('.'))
		throw InvalidValue();
	isFloat = 0;
	if (value.find_first_of('.') != std::string::npos)
		isFloat = 1;
	if (isFloat && value.size() < 2)
		throw InvalidValue();
	i = 0;
	while (i < value.size())
	{
		if (!isdigit(value[i]) && value[i] != '.')
			throw InvalidValue();
		i++;
	}
	try
	{
		if (isFloat)
			testFloat = std::stof(value);
		else
			testInt = std::stoi(value);
	}
	catch(const std::exception& e)
	{
		throw InvalidValue();
	}
}

//not static
float	BitcoinExchange::findExchangeRate(const Date& date)
{
	std::map<Date, float>::iterator it = m_database.find(date);

    if (it != m_database.end())
		return (it->second);
	it = m_database.upper_bound(date);
	if (it != m_database.begin())
		it--;
	return (it->second);
}
