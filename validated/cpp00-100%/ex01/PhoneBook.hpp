#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact		m_contacts[8];
	unsigned	m_saveIndex;
	unsigned	m_contactNb;
	void	truncatedAtTenDisplay(const std::string& str) const;
	void	displayContactInTab(unsigned index) const;
	void	displayTabTitles() const;
public:
	PhoneBook();
	PhoneBook(const PhoneBook& other);
	PhoneBook&	operator=(const PhoneBook& other);
	~PhoneBook();
	void	displayContactsTab() const;
	void	displayContactInformation(unsigned index) const;
	void	addContact(
			std::string firstName, 
			std::string lastName, 
			std::string nickname, 
			std::string phoneNumber, 
			std::string darkestSecret
			);
	unsigned	getContactNb() const;
};

#endif