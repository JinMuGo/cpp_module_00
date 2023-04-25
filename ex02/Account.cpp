/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:08:15 by jgo               #+#    #+#             */
/*   Updated: 2023/04/23 18:04:09 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(getNbAccounts()), _amount(initial_deposit), _nbDeposits(0),
	  _nbWithdrawals(0) {
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "created\n";
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "closed\n";
}

int Account::getNbAccounts(void) { return (_nbAccounts); }

int Account::getTotalAmount(void) { return (_totalAmount); }

int Account::getNbDeposits(void) { return (_totalNbDeposits); }

int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();

	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << "\n";
}

void Account::_displayTimestamp(void) {
	const time_t now = time(NULL);
	const struct tm *timeinfo = localtime(&now);
	char timestamp[42] = {0};

	strftime(timestamp, 42, "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << timestamp;
}

void Account::displayStatus(void) const {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << "\n";
}

void Account::makeDeposit(int deposit) {
	const int p_amount = _amount;

	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal) {
	const int p_amount = this->checkAmount();

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	if (withdrawal > this->checkAmount()) {
		std::cout << "withdrawal:refused\n";
		return (false);
	}

	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;

	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << "\n";
	return (true);
}

int Account::checkAmount(void) const { return (this->_amount); }
