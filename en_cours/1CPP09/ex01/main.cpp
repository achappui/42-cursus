#include "RPN.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Expecting exactly 1 argument !" << std::endl;
		return (1);
	}
	try
	{
        RPN calculator;
		calculator.replaceInstructions(argv[1]);
        
        int	result;

	    std::cout << "Instructions: ";
	    calculator.displayInstructions();
	    result = calculator.calculResult();
	    std::cout << "Result: " << result << std::endl;
    
	}
    catch (const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }

   
	return (0);
}
