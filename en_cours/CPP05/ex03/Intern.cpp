#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{}

AForm	*Intern::makeForm(const std::string formName, const std::string target) const
{
	const char	*formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	unsigned	i;
	AForm		*newForm;
	
	i = 0;
	while (i < 3 && formName != formNames[i])
		i++;
	switch (i)
	{
		case 0:
			newForm = new ShrubberyCreationForm(target);
			break;
		case 1:
			newForm = new RobotomyRequestForm(target);
			break;
		case 2:
			newForm = new PresidentialPardonForm(target);
			break;
		default:
			newForm = NULL;
			break;
	}
	return (newForm);
}
