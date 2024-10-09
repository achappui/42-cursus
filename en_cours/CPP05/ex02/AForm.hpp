#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string	m_name;
	bool				m_isSigned;
	const unsigned		m_gradeToSign;
	const unsigned		m_gradeToExecute;
	const std::string	m_target;
public:
	class FormNotSignedException : public std::exception {const char* what() const throw();};
	AForm();
	AForm(const std::string name, const unsigned gradeToSign, const unsigned gradeToExecute, const std::string target);
	AForm(const AForm& other);
	AForm&	operator=(const AForm& other);
	virtual ~AForm();

	int			beSigned(Bureaucrat& bureaucrat);
	unsigned	getGradeToSign(void) const;
	unsigned	getGradeToExecute(void) const;
	bool		getIsSigned(void) const;
	std::string	getName(void) const;
	std::string	getTarget(void) const;
	virtual void	execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif