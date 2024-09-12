#include "tools.hpp"
#include <stdio.h>

std::string	nextBlock(std::ifstream& file)
{
	char			charBuffer[BUFFER_SIZE];
	std::string		strBuffer;
	std::streamsize	bytesRead;

	file.read(charBuffer, BUFFER_SIZE);
	bytesRead = file.gcount();
	strBuffer.assign(charBuffer, bytesRead);
	return (strBuffer);
}

void	writeWritableContent(
		std::string& chunk,
		std::ifstream& fileFrom,
		std::ofstream& fileTo,
		std::string& strSearch, 
		std::string& strReplace
		)
{
	size_t	pos;

	if (strSearch.empty())
	{
		fileTo.write(chunk.c_str(), chunk.length());
		chunk.clear();
		return ;
	}
	pos = chunk.find(strSearch.c_str(), 0);
	while (pos != std::string::npos)
	{
		fileTo.write(chunk.c_str(), pos);
		if (fileTo.fail())
			return ;
		fileTo.write(strReplace.c_str(), strReplace.length());
		if (fileTo.fail())
			return ;
		chunk = chunk.substr(pos + strSearch.length());
		pos = chunk.find(strSearch.c_str(), 0);
	}
	if (fileFrom.eof())
		fileTo.write(chunk.c_str(), chunk.length());
}

int	processingLoop(
	std::ifstream& fileFrom, 
	std::ofstream& fileTo,
	std::string& strSearch, 
	std::string& strReplace
	)
{
	std::string	chunk;

	while (!fileFrom.eof())
	{
		chunk += nextBlock(fileFrom);
		if (fileFrom.fail() && !fileFrom.eof())
		{
			std::cerr << "Error: Problem while reading file." << std::endl;
			return (0);
		}
		writeWritableContent(chunk, fileFrom, fileTo, strSearch, strReplace);
		if (fileTo.fail())
		{
			std::cerr << "Error: Problem while writing in file." << std::endl;
			return (0);
		}
	}
	return (1);
}