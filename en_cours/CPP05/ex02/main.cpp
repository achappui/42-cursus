#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	arnold("Arnold", 150);
	Bureaucrat	gaspar("Gaspar", 1);

	ShrubberyCreationForm	sc_form("home");
	RobotomyRequestForm		rr_form("Mathew");
	PresidentialPardonForm	pp_form("Teo");

	std::cout << arnold << std::endl;
	std::cout << gaspar << std::endl;
	std::cout << sc_form << std::endl;
	std::cout << rr_form << std::endl;
	std::cout << pp_form << std::endl;

	arnold.signForm(sc_form);
	arnold.executeForm(sc_form);
	gaspar.executeForm(sc_form);

	gaspar.signForm(sc_form);
	gaspar.signForm(rr_form);
	gaspar.signForm(pp_form);
	gaspar.executeForm(sc_form);
	gaspar.executeForm(rr_form);
	gaspar.executeForm(pp_form);

	return (0);
}