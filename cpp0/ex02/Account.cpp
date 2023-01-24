#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

void	Account::_displayTimestamp( void ) {
    time_t raw_time;
    std::time(&raw_time);
    tm *clean_time = gmtime(&raw_time);
    std::clog << "[" << clean_time->tm_year + 1900
    << std::setfill('0') << std::setw(2) << (clean_time->tm_mon + 1) 
    << std::setfill('0') << std::setw(2) << clean_time->tm_mday << "_" 
    << std::setfill('0') << std::setw(2) << (clean_time->tm_hour + 1) % 24
    << std::setfill('0') << std::setw(2) << clean_time->tm_min
    << std::setfill('0') << std::setw(2) << clean_time->tm_sec
    <<"] ";
}

int	Account::getNbAccounts( void ) {
    return (_nbAccounts);
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

Account::~Account(void) {
    std::cout << "Destroyed:" << this->_accountIndex << std::endl;
}

void	Account::makeDeposit( int deposit ) {
    this->_amount += deposit;    
    this->_nbDeposits += 1;
}
bool	Account::makeWithdrawal( int withdrawal ) {
    if (this->_amount - withdrawal >= 0) //Can withdrawl
    {
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        Account::_totalNbWithdrawals += 1;
        return (true);
    }
    //can't withdraw
    return (false);
}

int		Account::checkAmount( void ) const {
    return (42);
}

void	Account::displayStatus( void ) const {
    // Account::_displayTimestamp();
}