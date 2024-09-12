#ifndef TOOLS_HPP
# define TOOLS_HPP

# include <string>
# include <iostream>
# include <fstream>

# define BUFFER_SIZE	20

int	processingLoop(
	std::ifstream& fileFrom, 
	std::ofstream& fileTo,
	std::string& strSearch, 
	std::string& strReplace
	);

#endif