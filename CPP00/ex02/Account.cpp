#include <ctime>
#include <string>
#include <iostream>
#include "Account.hpp"

// PUBLIC ==================================================
// static --------------------------------------------------
int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

// ---------------------------------------------------------

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	Account::_nbAccounts++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	return ;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return ;
}


void	Account::makeDeposit( int deposit )
{
	int	p_amount = this->_amount;

	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int		p_amount = this->_amount;
	bool	res = false;

	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		res = true;
	}

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	if (res)
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	} else
		std::cout << "withdrawal:refused" << std::endl;

	return (res);
}

int		Account::checkAmount( void ) const
{

	return 0;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;

	return ;
}

// =========================================================

// PRIVATE =================================================
// static --------------------------------------------------
int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

void	Account::_displayTimestamp( void )
{
	std::time_t	t = std::time(NULL);
	std::tm		*now = std::localtime(&t);
	char	buf[19];
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", now);
	std::cout << buf;
	return ;
}

// ---------------------------------------------------------

Account::Account( void ) {}

// =========================================================
