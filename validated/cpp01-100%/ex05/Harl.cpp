#include <iostream>
#include "colors.hpp"
#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout << RED;
	std::cout << "[ DEBUG ]";
	std::cout << OLIVE;
	std::cout << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-special-ketchup burger. ";
	std::cout << std::endl;
	std::cout << "I really do!";
	std::cout << std::endl;
	std::cout << RESET;
}

void	Harl::info(void)
{
	std::cout << RED;
	std::cout << "[ INFO ]";
	std::cout << OLIVE;
	std::cout << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!";
	std::cout << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
	std::cout << RESET;
}

void	Harl::warning(void)
{
	std::cout << RED;
	std::cout << "[ WARNING ]";
	std::cout << std::endl;
	std::cout << OLIVE;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
	std::cout << "whereas you started working here since last month.";
	std::cout << std::endl;
	std::cout << RESET;
}

void	Harl::error(void)
{
	std::cout << RED;
	std::cout << "[ ERROR ]";
	std::cout << std::endl;
	std::cout << OLIVE;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
	std::cout << RESET;
}

void	Harl::complain(std::string level)
{
	void (Harl::*complainList[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
		};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i])
		{
			(this->*complainList[i])();
			return;
		}
	}
}
