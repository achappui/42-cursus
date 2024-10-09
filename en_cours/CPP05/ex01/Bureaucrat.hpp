# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Form;

class Bureaucrat
{
private:
	const std::string	m_name;
	unsigned			m_grade;
public:
    class GradeTooHighException : public std::exception {const char* what() const throw();};
    class GradeTooLowException : public std::exception {const char* what() const throw();};

	Bureaucrat();
	Bureaucrat(const std::string name, unsigned char grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat&	operator=(const Bureaucrat& other);
	~Bureaucrat();

	void			signForm(Form& formToSign);
	std::string		getName(void) const;
	unsigned		getGrade(void) const;
	void			incrementGrade(void);
	void			decrementGrade(void);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif