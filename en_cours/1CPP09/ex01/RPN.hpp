#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <stdexcept>

# define OPERATORS	"+-/*"

class RPN
{
private:
	const std::string	m_operators;
	std::string			m_instructions;
	void	validateInstructions(std::string instructions) const;

public:
	class InvalidInstructions : public std::exception {public: const char *what() const throw() {return ("Invalid instructions !");}};
    class ZeroDivision : public std::exception {public: const char *what() const throw() {return ("Error division by 0 !");}};

	RPN();
	RPN(const std::string& instructions);
	RPN(const RPN& other);
	RPN&	operator=(const RPN& other);
	~RPN();

	void	displayInstructions(void) const;
	void	replaceInstructions(const std::string& newInstructions);
	int		calculResult(void) const;
};


#endif
