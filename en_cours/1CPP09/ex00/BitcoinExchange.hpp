#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include "Date.hpp"

class BitcoinExchange
{
private:
	static void		validateLine(std::string line, std::string separator);
	static Date		extractDateFromLine(std::string line, std::string separator);
	static float	extractValueFromLine(std::string line, std::string separator);

	std::map<Date, float>	m_database;

	float	findExchangeRate(const Date& date);

public:
	class EmptyDatabase : public std::exception {public: const char *what() const throw() {return ("Empty database !");}};
	class FileOpenError : public std::exception {public: const char *what() const throw() {return ("Could not open the file !");}};
	class InvalidLine : public std::exception {public: const char *what() const throw() {return ("Invalid line !");}};
	class InvalidValue : public std::exception {public: const char *what() const throw() {return ("Invalid value !");}};

	BitcoinExchange();
	BitcoinExchange(std::string databasePath);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void	loadDatabase(std::string databasePath);
	void	displayValuesFromFile(std::string filePath);
};

#endif
