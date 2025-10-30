#include "Date.hpp"
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

void	Date::validateDateFormat(const std::string& str)
{
	if (str.size() != 10 || \
		!isdigit(str[0]) || \
		!isdigit(str[1]) || \
		!isdigit(str[2]) || \
		!isdigit(str[3]) || \
		str[4] != '-' || \
		!isdigit(str[5]) || \
		!isdigit(str[6]) || \
		str[7] != '-' || \
		!isdigit(str[8]) || \
		!isdigit(str[9]))
		throw InvalidDateFormat();
}

void	Date::validateDate(const Date& date)
{
	Date		today;
	unsigned	year;
	unsigned	month;
	unsigned	day;

	year = date.getYear();
	month = date.getMonth();
	day = date.getDay();
	today = todaysDate();
	if (date > today)
		throw InvalidDate();
	if (year == 0 || month == 0 || day == 0)
		throw InvalidDate();
	if (month > 12)
		throw InvalidDate();
	if (month == 2 && ((day > 28 && !isLeapYear(year)) || day > 29))
		throw InvalidDate();
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
		throw InvalidDate();
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw InvalidDate();
}

std::string	Date::todaysDate(void)
{
    std::time_t			now = std::time(0);
    std::tm				*localTime = std::localtime(&now);
    std::stringstream	ss;
	std::string			date_str;

    ss << std::setw(4) << std::setfill('0') << 1900 + localTime->tm_year
       << "-"
       << std::setw(2) << std::setfill('0') << 1 + localTime->tm_mon
       << "-"
       << std::setw(2) << std::setfill('0') << localTime->tm_mday;
    date_str = ss.str();
	return (date_str);
}

bool Date::isLeapYear(unsigned year) {return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));}

Date::Date()
	:	m_date(todaysDate())
{}

Date::Date(std::string date)
	:	m_date(todaysDate())
{
	validateDateFormat(date);
	m_date = date;
}

Date::Date(const Date& other)
	:	m_date(other.m_date)
{}

Date&	Date::operator=(const Date& other)
{
	if (this != &other)
	{
		m_date = other.m_date;
	}
	return (*this);
}

bool Date::operator<(const Date& other) const {return (m_date.compare(other.m_date) < 0);}
bool Date::operator<=(const Date& other) const {return (m_date.compare(other.m_date) < 0 || m_date.compare(other.m_date) == 0);}
bool Date::operator>(const Date& other) const {return (m_date.compare(other.m_date) > 0);}
bool Date::operator>=(const Date& other) const {return (m_date.compare(other.m_date) > 0 || m_date.compare(other.m_date) == 0);}
bool Date::operator==(const Date& other) const {return (m_date.compare(other.m_date) == 0);}
bool Date::operator!=(const Date& other) const {return (m_date.compare(other.m_date) != 0);}

Date::~Date()
{}

void	Date::setDate(std::string date)
{
	validateDateFormat(date);
	m_date = date;
}

std::string	Date::getDate(void) const {return (m_date);}

unsigned	Date::getYear(void) const {
	std::istringstream	iss(m_date.substr(0,4));
	int			value;

	iss >> value;
	if (iss.fail() || !iss.eof())
		throw InvalidDate();
	return (value);
}

unsigned	Date::getMonth(void) const {
	std::istringstream	iss(m_date.substr(5,2));
	int			value;

	iss >> value;
	if (iss.fail() || !iss.eof())
		throw InvalidDate();
	return (value);
}

unsigned	Date::getDay(void) const {
	std::istringstream	iss(m_date.substr(8,2));
	int			value;

	iss >> value;
	if (iss.fail() || !iss.eof())
		throw InvalidDate();
	return (value);
}

//out
std::ostream&	operator<<(std::ostream& os, const Date& date)
{
    os << date.getDate();
    return (os);
}
