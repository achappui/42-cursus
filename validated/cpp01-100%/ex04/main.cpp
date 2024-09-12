#include "tools.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Invalid arguments." << std::endl;
		return (1);
	}

	std::string	fileFromPath = argv[1];
	std::string	fileToPath = fileFromPath + ".replace";
	std::string	strSearch = argv[2];
	std::string	strReplace = argv[3];

	std::ifstream	fileFrom(fileFromPath.c_str(), std::ios::binary);
    if (!fileFrom)
	{
        std::cerr << "Error: Unable to open the file." << std::endl;
        return (1);
    }
    std::ofstream	fileTo(fileToPath.c_str(), std::ios::binary);
    if (!fileTo)
	{
        std::cerr << "Error: Unable to create the file." << std::endl;
        return (1);
    }
	if (processingLoop(fileFrom, fileTo, strSearch, strReplace) == 0)
	{
		fileFrom.close();
		fileTo.close();
		if (std::remove(fileToPath.c_str()) != 0)
			std::cerr << "Error: Unable to remove the file." << std::endl;
		return (1);
	}
	fileFrom.close();
	fileTo.close();
	return (0);
}