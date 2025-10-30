#ifndef DATE_HPP
# define DATE_HPP

# include <string>

class Date
{
private:
	std::string	m_date;

public:
	class InvalidDateFormat : public std::exception {public: const char *what() const throw() {return ("Invalid date format !");}};
	class InvalidDate : public std::exception {public: const char *what() const throw() {return ("Invalid date !");}};

	static void			validateDateFormat(const std::string& str);
	static void			validateDate(const Date& date);
	static std::string	todaysDate(void);
	static bool 		isLeapYear(unsigned year);

	Date();
	Date(std::string date);
	Date(const Date& other);
	Date&	operator=(const Date& other);
    bool 	operator<(const Date& other) const;
    bool 	operator<=(const Date& other) const;
    bool 	operator>(const Date& other) const;
    bool 	operator>=(const Date& other) const;
    bool 	operator==(const Date& other) const;
    bool 	operator!=(const Date& other) const;
	~Date();

	void		setDate(std::string date);
	std::string	getDate(void) const;
	unsigned	getYear(void) const;
	unsigned	getMonth(void) const;
	unsigned	getDay(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Date& date);

#endif
