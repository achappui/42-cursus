#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

class Account
{
public:
	typedef Account		t;
	Account(int initial_deposit);
	~Account();
	static int	getNbAccounts();
	static int	getTotalAmount();
	static int	getNbDeposits();
	static int	getNbWithdrawals();
	static void	displayAccountsInfos();
	void		makeDeposit(int deposit);
	bool		makeWithdrawal(int withdrawal);
	int			checkAmount() const;
	void		displayStatus() const;
private:
	static int	m_nbAccounts;
	static int	m_totalAmount;
	static int	m_totalNbDeposits;
	static int	m_totalNbWithdrawals;
	static int	m_accountId;
	int			m_accountIndex;
	int			m_amount;
	int			m_nbDeposits;
	int			m_nbWithdrawals;
	static void	displayTimestamp();
	Account();
};

#endif
