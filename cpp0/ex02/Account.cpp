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
    std::cout << "[" << clean_time->tm_year + 1900
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
    Account::_totalAmount += initial_deposit;
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
    Account::_totalAmount -= this->_amount;
    Account::_totalNbDeposits -= this->_nbDeposits;
    Account::_totalNbWithdrawals -= this->_nbWithdrawals;
    Account::_accountIndex -= 1;
}

void	Account::makeDeposit( int deposit ) {
    int previous_amount = this->_amount;
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits += 1;
    this->_totalNbDeposits += 1;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ';'
    << "p_amount:" << previous_amount << ';'
    << "deposit:" << deposit << ';'
    << "amount:" << this->_amount  << ';'
    << "nb_deposits:" << this->_nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal ) {
    int previous_amount = this->_amount;
    
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ';'
    << "p_amount:" << previous_amount << ';'
    << "withdrawal:";
    if (this->_amount - withdrawal < 0) //if Account can't withdraw log refused and make an early return
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    this->_nbWithdrawals += 1;
    Account::_totalNbWithdrawals += 1;
    std::cout << withdrawal << ';'
    << "amount:" << this->_amount  << ';'
    << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

int		Account::checkAmount( void ) const {
    return (42);
}

void	Account::displayStatus( void ) const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" 
    << "amount:" << this->_amount  << ";"
    << "deposits:" << this->_nbDeposits << ";"
    << "withdrawals:" << this->_nbWithdrawals << std::endl;
}