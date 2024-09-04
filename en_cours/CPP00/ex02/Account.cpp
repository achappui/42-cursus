#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::m_nbAccounts = 0;
int	Account::m_totalAmount = 0;
int	Account::m_totalNbDeposits = 0;
int	Account::m_totalNbWithdrawals = 0;
int	Account::m_accountId = 0;

Account::Account()
:	m_accountIndex(m_accountId), 
	m_amount(0), 
	m_nbDeposits(0),
	m_nbWithdrawals(0)
{
	displayTimestamp();
	std::cout	<< ' '
				<< "index:" << m_accountIndex << ';'
				<< "amount:" << m_amount << ';'
				<< "created"
				<< std::endl;
	m_accountId++;
	m_nbAccounts++;
}

Account::Account(int initial_deposit)
:	m_accountIndex(m_accountId), 
	m_amount(0), 
	m_nbDeposits(0),
	m_nbWithdrawals(0)
{
	m_amount += initial_deposit;
	m_totalAmount += initial_deposit;
	displayTimestamp();
	std::cout	<< ' '
				<< "index:" << m_accountIndex << ';'
				<< "amount:" << m_amount << ';'
				<< "created"
				<< std::endl;
	m_accountId++;
	m_nbAccounts++;
}

Account::~Account()
{
	displayTimestamp();
	std::cout	<< ' '
				<< "index:" << m_accountIndex << ';'
				<< "amount:" << m_amount << ';'
				<< "closed"
				<< std::endl;
	m_totalNbWithdrawals -= m_nbWithdrawals;
	m_totalNbDeposits -= m_nbDeposits;
	m_totalAmount -= m_amount;
	m_nbAccounts--;
}

void	Account::displayAccountsInfos()
{
	displayTimestamp();
	std::cout	<< ' '
				<< "accounts:" << m_nbAccounts << ';'
				<< "total:" << m_totalAmount << ';'
				<< "deposits:" << m_totalNbDeposits << ';'
				<< "withdrawals:" << m_totalNbWithdrawals
				<< std::endl;
}


void	Account::makeDeposit(int deposit)
{
	displayTimestamp();
	std::cout	<< ' '
				<< "index:" << m_accountIndex << ';'
				<< "p_amount:" << m_amount << ';'
				<< "deposit:" << deposit << ';';
	m_amount += deposit;
	m_totalAmount += deposit;
	m_nbDeposits++;
	m_totalNbDeposits++;
	std::cout	<< "amount:" << m_amount << ';'
				<< "nb_deposits:" << m_nbDeposits
				<< std::endl;
}


bool	Account::makeWithdrawal(int withdrawal)
{
	displayTimestamp();
	std::cout	<< ' '
				<< "index:" << m_accountIndex << ';'
				<< "p_amount:" << m_amount << ';'
				<< "withdrawal:" << withdrawal << ';';
	if (withdrawal > m_amount)
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return (0);
	}
	else
	{
		m_amount -= withdrawal;
		m_totalAmount -= withdrawal;
		m_nbWithdrawals++;
		m_totalNbWithdrawals++;
		std::cout	<< "withdrawal:" << withdrawal << ';'
				<< "amount:" << m_amount << ';'
				<< "nb_withdrawals:" << m_nbWithdrawals
				<< std::endl;
		return (1);
	}
}

void	Account::displayStatus() const
{
	displayTimestamp();
	std::cout	<< ' '
				<< "index:" << m_accountIndex << ';'
				<< "amount:" << m_amount << ';'
				<< "deposits:" << m_nbDeposits << ';'
				<< "withdrawals:" << m_nbWithdrawals
				<< std::endl;
}

void	Account::displayTimestamp()
{
	std::time_t	t;
	std::tm*	now;

	t = std::time(0);
	now = std::localtime(&t);
	std::cout	<< '['
				<< (now->tm_year + 1900)
				<< std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
				<< std::setw(2) << std::setfill('0') << now->tm_mday
				<< '_'
				<< std::setw(2) << std::setfill('0') << now->tm_hour
				<< std::setw(2) << std::setfill('0') << now->tm_min
				<< std::setw(2) << std::setfill('0') << now->tm_sec
				<< ']';
}

int	Account::checkAmount() const {return (m_amount);}

int	Account::getTotalAmount() {return (m_totalAmount);}
int	Account::getNbAccounts() {return (m_nbAccounts);}
int	Account::getNbDeposits() {return(m_totalNbDeposits);}
int	Account::getNbWithdrawals() {return(m_totalNbWithdrawals);}