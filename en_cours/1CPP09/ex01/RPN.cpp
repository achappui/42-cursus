#include "RPN.hpp"
#include <iostream>

//public
RPN::RPN()
	:	m_operators(OPERATORS),
		m_instructions("1 1 +")
{}

RPN::RPN(const std::string& instructions)
	:	m_operators(OPERATORS),
		m_instructions()
{
	validateInstructions(instructions);
	m_instructions = instructions;
}

RPN::RPN(const RPN& other)
	:	m_operators(other.m_operators),
		m_instructions(other.m_instructions)
{}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		m_instructions = other.m_instructions;
	}
	return (*this);
}

RPN::~RPN()
{}

void	RPN::displayInstructions(void) const
{
	std::cout << m_instructions << std::endl;
}

void	RPN::replaceInstructions(const std::string& newInstructions)
{
	validateInstructions(newInstructions);
	m_instructions = newInstructions;
}

int	RPN::calculResult(void) const
{
	std::stack<int>	stack;
	int				tmpResult;
	int				tab[2];

	for (size_t i = 0; i != m_instructions.size(); i++)
	{
		if (i & 1)
			continue;
		if (isdigit(m_instructions[i]))
			stack.push(static_cast<int>(m_instructions[i] - 48));
		else
		{
			tab[1] = stack.top();
			stack.pop();
			tab[0] = stack.top();
			stack.pop();
			switch (m_instructions[i]) //Unfortunately we have to change those lines if we change the operator Define
			{
			case '+':
				tmpResult = tab[0] + tab[1];
				break;
			case '-':
				tmpResult = tab[0] - tab[1];
				break;
			case '/':
                if (tab[1] == 0)
                {
                    throw ZeroDivision();
                }
                else
                {
				    tmpResult = tab[0] / tab[1];
                }
				break;
			case '*':
				tmpResult = tab[0] * tab[1];
				break;
			}
			stack.push(tmpResult);
		}
	}
	return (stack.top());
}

//private
void	RPN::validateInstructions(std::string instructions) const
{
	unsigned	stackSize;

	stackSize = 0;
	for (size_t i = 0; i != instructions.size(); i++)
	{
		if (i & 1)
		{
			if (instructions[i] != ' ')
				throw InvalidInstructions();
			continue;
		}
		if (isdigit(instructions[i]))
			stackSize++;
		else if (m_operators.find(instructions[i]) != std::string::npos)
		{
			if (stackSize < 2)
				throw InvalidInstructions();
			stackSize--;
		}
		else
			throw InvalidInstructions();
	}
	if (stackSize != 1)
		throw InvalidInstructions();
}
