#include <iostream>

int main(int argc, char **argv)
{
	unsigned int	i;
	unsigned int	j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < (unsigned int)argc)
		{
			j = 0;
			while (argv[i][j])
			{
				argv[i][j] = std::toupper(argv[i][j]);
				j++;
			}
			std::cout << argv[i];
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}