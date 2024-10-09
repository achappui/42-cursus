#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	:	AForm("ShrubberyCreationForm", 145, 137, "Default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	:	AForm("ShrubberyCreationForm", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:	AForm(other)
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	else if (!getIsSigned())
		throw AForm::FormNotSignedException();
	std::ofstream	outfile((getTarget() + "_shrubbery").c_str());
	outfile << "       ###" << std::endl;
	outfile << "      #o###" << std::endl;
	outfile << "    #####o###" << std::endl;
	outfile << "   #o#\\#|#/###" << std::endl;
	outfile << "    ###\\|/#o#" << std::endl;
	outfile << "     # }|{  #" << std::endl;
	outfile << "       }|{" << std::endl;
	outfile << std::endl;
	outfile << "       ###" << std::endl;
	outfile << "      #o###" << std::endl;
	outfile << "    #####o###" << std::endl;
	outfile << "   #o#\\#|#/###" << std::endl;
	outfile << "    ###\\|/#o#" << std::endl;
	outfile << "     # }|{  #" << std::endl;
	outfile << "       }|{" << std::endl;
	outfile.close();
}
