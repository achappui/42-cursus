#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Bureaucrat;

class Form
{
private:
	const std::string	m_name;
	bool				m_isSigned;
	const unsigned		m_gradeToSign;
	const unsigned		m_gradeToExecute;
public:
	Form();
	Form(const std::string name, const unsigned gradeToSign, const unsigned gradeToExecute);
	Form(const Form& other);
	Form&	operator=(const Form& other);
	~Form();

	int			beSigned(Bureaucrat& bureaucrat);
	unsigned	getGradeToSign(void) const;
	unsigned	getGradeToExecute(void) const;
	bool		getIsSigned(void) const;
	std::string	getName(void) const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif