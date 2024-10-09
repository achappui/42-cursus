#include "Form.hpp"
#include "colors.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form()
	:	m_name("Default"),
		m_isSigned(0),
		m_gradeToSign(150),
		m_gradeToExecute(150)
{}

Form::Form(const std::string name, const unsigned gradeToSign, const unsigned gradeToExecute)
	:	m_name(name),
		m_isSigned(0),
		m_gradeToSign(gradeToSign),
		m_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form& other)
	:	m_name(other.m_name),
		m_isSigned(other.m_isSigned),
		m_gradeToSign(other.m_gradeToSign),
		m_gradeToExecute(other.m_gradeToExecute)
{}

Form&	Form::operator=(const Form& other)
{
	if (this == &other)
	{
		m_isSigned = other.m_isSigned;
	}
	return (*this);
}

Form::~Form()
{}

int	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= m_gradeToSign)
	{
		m_isSigned = 1;
		return (1);
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

unsigned	Form::getGradeToSign(void) const {return (m_gradeToSign);}
unsigned	Form::getGradeToExecute(void) const {return (m_gradeToExecute);}
bool		Form::getIsSigned(void) const {return (m_isSigned);}
std::string	Form::getName(void) const {return (m_name);}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << SALMON;
	os	<< "Form: " << form.getName() << ", "
		<< "Min grade to sign: " << form.getGradeToSign() << ", "
		<< "Min grade to execute: " << form.getGradeToExecute() << ", "
		<< "Is signed: ";
	if (form.getIsSigned())
		os << "yes";
	else
		os << "no";
	os << RESET;
	return (os);
}