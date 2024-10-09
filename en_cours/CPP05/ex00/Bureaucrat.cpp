#include "Bureaucrat.hpp"
#include "colors.hpp"
#include <iostream>

const char*	Bureaucrat::GradeTooHighException::what() const throw() {return ("Grade too high !");}
const char*	Bureaucrat::GradeTooLowException::what() const throw() {return ("Grade too low !");}

Bureaucrat::Bureaucrat()
	:	m_name("Default"),
		m_grade(150)
{}

Bureaucrat::Bureaucrat(const std::string name, unsigned char grade)
	:	m_name(name),
		m_grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:	m_name(other.m_name),
		m_grade(other.m_grade)
{}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		m_grade = other.m_grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

void	Bureaucrat::incrementGrade(void)
{
	if (m_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		m_grade--;
		std::cout << OLIVE;
		std::cout << m_name << "'s grade got incremented !" << std::endl;
		std::cout << RESET;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	if (m_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		m_grade++;
		std::cout << OLIVE;
		std::cout << m_name << "'s grade got decremented !" << std::endl;
		std::cout << RESET;
	}
}

std::string		Bureaucrat::getName(void) const {return (m_name);}
unsigned		Bureaucrat::getGrade(void) const {return (m_grade);}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << OLIVE;
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	os << RESET;
	return (os);
}