#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.hpp"
#include <iostream>

const char*	AForm::FormNotSignedException::what() const throw() {return ("Form not signed !");}

AForm::AForm()
	:	m_name("Default"),
		m_isSigned(0),
		m_gradeToSign(150),
		m_gradeToExecute(150),
		m_target("Default")
{}

AForm::AForm(const std::string name, const unsigned gradeToSign, const unsigned gradeToExecute, const std::string target)
	:	m_name(name),
		m_isSigned(0),
		m_gradeToSign(gradeToSign),
		m_gradeToExecute(gradeToExecute),
		m_target(target)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm& other)
	:	m_name(other.m_name),
		m_isSigned(other.m_isSigned),
		m_gradeToSign(other.m_gradeToSign),
		m_gradeToExecute(other.m_gradeToExecute),
		m_target(other.m_target)
{}

AForm&	AForm::operator=(const AForm& other)
{
	if (this == &other)
	{
		m_isSigned = other.m_isSigned;
	}
	return (*this);
}

AForm::~AForm()
{}

int	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= m_gradeToSign)
	{
		m_isSigned = 1;
		return (1);
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

unsigned	AForm::getGradeToSign(void) const {return (m_gradeToSign);}
unsigned	AForm::getGradeToExecute(void) const {return (m_gradeToExecute);}
bool		AForm::getIsSigned(void) const {return (m_isSigned);}
std::string	AForm::getName(void) const {return (m_name);}
std::string	AForm::getTarget(void) const {return (m_target);}

std::ostream& operator<<(std::ostream& os, const AForm& form)
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
