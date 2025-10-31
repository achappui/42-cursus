#include "uArray.hpp"
#include <sstream>
#include <iostream>

int parsingByArgv(int argc, char **argv, uArray &arr)
{
	size_t		        i = 0;
	unsigned int		number = 0;
	unsigned	        *unsignedArray = NULL;
    std::istringstream  iss;

	unsignedArray = new unsigned[argc];
	argv++;
	while (argv[i] != NULL)
	{
        iss.clear();
        iss.str(argv[i]);
        iss >> number;
        if (iss.fail() || !iss.eof() || !std::isdigit(argv[i][0]))
        {
            delete[] unsignedArray;
            return (-1);
        }
		unsignedArray[i] = number;
		i++;
	}
    arr.size = i;
    arr.array = unsignedArray;
	return (0);
}

int parsingBySplitting(char *str, uArray &arr)
{
    bool                newWord = 1;
    size_t              size = 0;
    size_t              i = 0;
    unsigned*           unsignedArray = NULL;
    std::istringstream  iss;
    unsigned int        number;

    while (str[i])
    {
        if (std::isspace(str[i]))
           newWord = 1;
        else if (std::isdigit(str[i]))
        {
            if (newWord == 1)
                size++;
            newWord = 0;
        }
        else
            return (-1);
        i++;
    }
    if (size > 1000000)
        return (-1);
    unsignedArray = new unsigned[size + 1];
    i = 0;
    newWord = 1;
    size = 0;
    while (str[i])
    {
        if (std::isspace(str[i]))
            newWord = 1;
        else if (std::isdigit(str[i]))
        {
            if (newWord == 1)
            {
                iss.clear();
                iss.str(str + i);
                iss >> number;
                if (iss.fail())
                {
                    delete[] unsignedArray;
                    return (-1);
                }
                else
                    unsignedArray[size] = number;
                size++;
            }
            newWord = 0;
        }
        else
        {
            delete[] unsignedArray;
            return (-1);
        }
        i++;
    }
    if (size == 0)
        return (-1);
    arr.size = size;
    arr.array = unsignedArray;
    return (0);
}
