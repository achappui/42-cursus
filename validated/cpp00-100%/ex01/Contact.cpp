#include "Contact.hpp"

//Constructors
Contact::Contact() {}

Contact::Contact(const Contact& other)
{
	this->m_firstName = other.m_firstName;
	this->m_lastName = other.m_lastName;
	this->m_nickname = other.m_nickname;
	this->m_phoneNumber = other.m_phoneNumber;
	this->m_darkestSecret = other.m_darkestSecret;
}

Contact& Contact::operator=(const Contact& other)
{
	if (this != &other) 
	{
		this->m_firstName = other.m_firstName;
		this->m_lastName = other.m_lastName;
		this->m_nickname = other.m_nickname;
		this->m_phoneNumber = other.m_phoneNumber;
		this->m_darkestSecret = other.m_darkestSecret;
	}
	return (*this);
}

Contact::~Contact() {}

//Getters
const std::string& Contact::getFirstName() const {return (this->m_firstName);}
const std::string& Contact::getLastName() const {return (this->m_lastName);}
const std::string& Contact::getNickname() const {return (this->m_nickname);}
const std::string& Contact::getPhoneNumber() const {return (this->m_phoneNumber);}
const std::string& Contact::getDarkestSecret() const {return (this->m_darkestSecret);}

//Setters
void Contact::setFirstName(const std::string firstName) {this->m_firstName = firstName;}
void Contact::setLastName(const std::string lastName) {this->m_lastName = lastName;}
void Contact::setNickname(const std::string nickname) {this->m_nickname = nickname;}
void Contact::setPhoneNumber(const std::string phoneNumber) {this->m_phoneNumber = phoneNumber;}
void Contact::setDarkestSecret(const std::string darkestSecret) {this->m_darkestSecret = darkestSecret;}