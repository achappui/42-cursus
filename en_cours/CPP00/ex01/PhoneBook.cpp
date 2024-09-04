#include <iostream>
#include <string>
#include <iomanip>
#include "colors.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : m_saveIndex(0), m_contactNb(0) {}

PhoneBook::PhoneBook(const PhoneBook& other)
{
	unsigned	i;

	i = 0;
	while (i < 8)
	{
		this->m_contacts[i] = other.m_contacts[i];
		i++;
	}
}

PhoneBook&	PhoneBook::operator=(const PhoneBook& other)
{
	unsigned	i;

	if (this != &other)
	{
		i = 0;
		while (i < 8)
		{
			this->m_contacts[i] = other.m_contacts[i];
			i++;
		}
	}
	return (*this);
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::displayContactsTab() const
{
	unsigned	i;

	displayTabTitles();
	i = 0;
	while (i < this->m_contactNb)
	{
		displayContactInTab(i);
		i++;
	}
}

void	PhoneBook::displayContactInformation(unsigned index) const
{
	std::cout << "------------------" << std::endl;
	std::cout << "First Name:     " << m_contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name:      " << m_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname:       " << m_contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number:   " << m_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << m_contacts[index].getDarkestSecret() << std::endl;
	std::cout << "------------------" << std::endl;
}

void	PhoneBook::truncatedAtTenDisplay(const std::string& str) const
{
	if (str.length() > 10)
		std::cout << std::setw(10) << std::right << str.substr(0, 9) + '.';
	else
		std::cout << std::setw(10) << std::right << str;
}

void	PhoneBook::displayContactInTab(unsigned index) const
{
    std::cout << '|';
    truncatedAtTenDisplay(m_contacts[index].getFirstName());
    std::cout << '|';
    truncatedAtTenDisplay(m_contacts[index].getLastName());
    std::cout << '|';
    truncatedAtTenDisplay(m_contacts[index].getNickname());
    std::cout << '|';
    truncatedAtTenDisplay(m_contacts[index].getPhoneNumber());
    std::cout << '|';
    truncatedAtTenDisplay(m_contacts[index].getDarkestSecret());
    std::cout << '|' << std::endl;
}

void	PhoneBook::displayTabTitles() const
{
	std::cout << ' ';
	truncatedAtTenDisplay("First Name");
	std::cout << ' ';
	truncatedAtTenDisplay("Last Name");
	std::cout << ' ';
	truncatedAtTenDisplay("Nickname");
	std::cout << ' ';
	truncatedAtTenDisplay("Phone Number");
	std::cout << ' ';
	truncatedAtTenDisplay("Darkest Secret");
	std::cout << std::endl;
}

void	PhoneBook::addContact(
		std::string firstName, 
		std::string lastName, 
		std::string nickname, 
		std::string phoneNumber, 
		std::string darkestSecret
		)
{
	m_contacts[m_saveIndex].setFirstName(firstName);
	m_contacts[m_saveIndex].setLastName(lastName);
	m_contacts[m_saveIndex].setNickname(nickname);
	m_contacts[m_saveIndex].setPhoneNumber(phoneNumber);
	m_contacts[m_saveIndex].setDarkestSecret(darkestSecret);
	if (m_contactNb < 8)
		m_contactNb++;
	m_saveIndex++;
	if (m_saveIndex == 8)
		m_saveIndex = 0;
}

unsigned	PhoneBook::getContactNb() const {return (this->m_contactNb);}