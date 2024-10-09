#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.hpp"
#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm()
	:	AForm("RobotomyRequestForm", 72, 45, "Default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	:	AForm("RobotomyRequestForm", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	:	AForm(other)
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	else if (!getIsSigned())
		throw AForm::FormNotSignedException();

	std::cout << TEAL;
	std::cout << "* Drilling noises *" << std::endl;
	std::cout << RESET;
	std::srand(std::time(NULL));
	int	random = std::rand() % 2;
	if (random == 0)
	{
		std::cout << TEAL;
		std::cout << getTarget() << " has been robotomized successfully 50% of the time." << std::endl;
		std::cout << RESET;
	}
	else
	{
		std::cout << TEAL;
		std::cout << "The robotomy of " << getTarget() << " failed !" << std::endl;
		std::cout << RESET;
	}
}
