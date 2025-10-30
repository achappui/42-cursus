#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Missing file name !" << std::endl;
        return (-1);
    }
    else if (argc > 2) {
        std::cerr << "Too much file inputs !" << std::endl;
        return (-1);
    }
	try
	{
		BitcoinExchange	btcExchanger;

		btcExchanger.loadDatabase("data.csv");
		btcExchanger.displayValuesFromFile(argv[1]);
	}
	catch(const std::exception& e)
	{
	    std::cerr << e.what() << std::endl;
	}
	return (0);
}
