#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern	test_intern;
	AForm	*new_form1;
	AForm	*new_form2;

	Bureaucrat	arnold("Arnold", 150);
	Bureaucrat	gaspar("Gaspar", 1);

	new_form1 = test_intern.makeForm("presidential pardon", "gorilla");
	new_form2 = test_intern.makeForm("lkafjwiooi", "gorilla");

	std::cout << *new_form1 << std::endl;

	arnold.executeForm(*new_form1);
	gaspar.signForm(*new_form1);
	gaspar.executeForm(*new_form1);

	delete new_form1;
	delete new_form2;
	
	return (0);
}