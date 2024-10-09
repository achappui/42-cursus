#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm()
	:	AForm("PresidentialPardonForm", 25, 5, "Default")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	:	AForm("PresidentialPardonForm", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	:	AForm(other)
{}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	else if (!getIsSigned())
		throw AForm::FormNotSignedException();

	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
