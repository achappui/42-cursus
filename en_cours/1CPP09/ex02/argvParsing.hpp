#ifndef ARGVPARSING_HPP
# define ARGVPARSING_HPP

# include "uArray.hpp"

int parsingByArgv(int argc, char **argv, uArray &arr);
int parsingBySplitting(char *str, uArray &arr);

#endif
