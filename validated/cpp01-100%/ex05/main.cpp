#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("COMPOTES");
	harl.complain("ERROR");
	harl.complain("DEBUG");
	harl.complain("ERROR");

	return (0);
}