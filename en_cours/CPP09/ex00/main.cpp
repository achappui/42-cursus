#include "BitcoinExchange.hpp"
#include "Date.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		BitcoinExchange	btcExchanger;

		btcExchanger.loadDatabase("data.csv");
		btcExchanger.displayValuesFromFile("test.txt");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}