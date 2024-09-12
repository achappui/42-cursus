#include <cstring>
#include <iostream>
#include <sstream>
#include "colors.hpp"
#include "PhoneBook.hpp"

static int	checkIndexInput(std::string& input)
{
	unsigned	i;

	i = 0;
	while (input[i])
	{
		if (std::isdigit(input[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

std::string	askInputWithPrompt(std::string info)
{
	std::string	input;

	std::cout << SALMON;
	std::cout << info << ": ";
	std::cout << RESET;
	std::getline(std::cin, input);
	while (input.length() == 0)
	{
		std::cout << SALMON;
		std::cout << info << ": ";
		std::cout << RESET;
		std::getline(std::cin, input);
	}
	return (input);
}

static unsigned	askIndexInput(PhoneBook& phoneBook)
{
	std::string	input;
	unsigned	index;

	input = askInputWithPrompt("Choose index");
	while (checkIndexInput(input) == 0)
	{
		std::cout << "Index must be a number." << std::endl;
		input = askInputWithPrompt("Choose index");
	}
	std::stringstream ss(input);
	ss >> index;
	while (index >= phoneBook.getContactNb())
	{
		std::cout << "Please enter a valid index." << std::endl;
		input = askInputWithPrompt("Choose index");
		while (checkIndexInput(input) == 0)
		{
			std::cout << "Index must be a number." << std::endl;
			input = askInputWithPrompt("Choose index");
		}
		std::stringstream ss(input);
		ss >> index;
	}
	return (index);
}

void	askContactInformations(
		std::string& firstName,
		std::string& lastName,
		std::string& nickname,
		std::string& phoneNumber,
		std::string& darkestSecret
		)
{
	firstName = askInputWithPrompt("First name");
	lastName = askInputWithPrompt("Last name");
	nickname = askInputWithPrompt("Nickname");
	phoneNumber = askInputWithPrompt("Phone number");
	darkestSecret = askInputWithPrompt("Darkest secret");
}

int	main()
{
	PhoneBook	phoneBook;
	std::string	input;
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
	unsigned	index;

	input = askInputWithPrompt("Enter a command");
	while (input.compare("EXIT") != 0)
	{
		if (input.compare("ADD") == 0)
		{
			askContactInformations(
			firstName,
			lastName,
			nickname,
			phoneNumber,
			darkestSecret
			);
			phoneBook.addContact(
			firstName, 
			lastName, 
			nickname,
			phoneNumber,
			darkestSecret
			);
		}
		else if (input.compare("SEARCH") == 0)
		{
			std::cout << OLIVE;
			phoneBook.displayContactsTab();
			std::cout << RESET;
			if (phoneBook.getContactNb() > 0)
			{
				index = askIndexInput(phoneBook);
				std::cout << OLIVE;
				phoneBook.displayContactInformation(index);
				std::cout << RESET;
			}
		}
		input = askInputWithPrompt("Enter a command");
	}
	return (0);
}