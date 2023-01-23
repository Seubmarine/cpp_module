#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::getNbAccounts( void ) {
    return (Account::_nbAccounts);
}
int	Account::getTotalAmount( void ) {
    return (_totalAmount);
}
int	Account::getNbDeposits( void ) {
    return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void ) {
    return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout 
    << "accounts:" << Account::_nbAccounts << ";" 
    << "total:" << Account::_totalAmount << ";" 
    << "deposits:" << Account::_totalNbDeposits << ";"
    << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit ) {
    Account::_displayTimestamp();
    this->_accountIndex = Account::getNbAccounts();
    Account::_nbAccounts += 1;
    this->_amount = initial_deposit;
    std::cout << "index:" << this->_accountIndex << ";ammount:" << this->_amount << ";created" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
    this->_nbDeposits += 1;
    this->_nbWithdrawals 
}
bool	Account::makeWithdrawal( int withdrawal ) {
    if (this->_amount - withdrawal >= 0) //Can withdrawl
    {
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        Account::_totalNbWithdrawals += 1;
    }
}
	int		checkAmount( void ) const;
	void	displayStatus( void ) const {
        
    }


static void	_displayTimestamp( void ) {
    std::clog << "[" << std::time(NULL) << "] ";
}