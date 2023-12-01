/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:11:25 by jcasades          #+#    #+#             */
/*   Updated: 2023/10/29 18:27:26 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <limits>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

int  Account::getNbAccounts()
{
    return (_nbAccounts);
}

int	Account::getTotalAmount()
{
    return (_totalAmount);
}

int	Account::getNbDeposits ()
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}
//  format [YYYYMMDD_HHMMSS] + ' '
void Account::_displayTimestamp()
{
    std::time_t result = std::time(NULL);

    std::cout << std::setfill('0') <<"[" << 1900 + std::localtime(&result)->tm_year
                << std::setw(2) << 1 + std::localtime(&result)->tm_mon
                <<  std::setw(2) << std::localtime(&result)->tm_mday
                <<  "_"
                <<  std::setw(2) << std::localtime(&result)->tm_hour
                <<  std::setw(2) << std::localtime(&result)->tm_min
                <<  std::setw(2) << std::localtime(&result)->tm_sec 
                << "] " << std::flush;
}

// constr class account
Account::Account(int initial_deposit)
{
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

// destr class account
Account::~Account ()
{
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// print accounts, total, deposits, withdrawals
void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits () << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}
// take deposit update amount, number deposit
void	Account::makeDeposit(int deposit)
{
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << std::flush;
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

// return amount from account
int     Account::checkAmount() const
{
    return (_amount);
}

// take money from the account, take in param the amount that we want take, true if it's ok or false
bool   Account::makeWithdrawal(int withdrawal)
{
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << std::flush;
    if (checkAmount() >= withdrawal)
    {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;;
        _totalAmount -= withdrawal;
        std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
    else
    {
        std::cout << ":refused" << std::endl;
        return (false);
    }
}

// print index, amount, deposits, withdrawals
void	Account::displayStatus() const
{
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
