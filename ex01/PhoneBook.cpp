/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:21:14 by jgo               #+#    #+#             */
/*   Updated: 2023/04/23 18:59:40 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.h"

PhoneBook::PhoneBook() { curIdx = 0; }

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
	if (curIdx == 7)
		curIdx = 0;
	contactArr[curIdx].saveInfo(curIdx);
	curIdx++;
}

void PhoneBook::searchContact() {
	std::string input;
	int idx = -1;

	// prt Column
	std::cout << "---------------------------------------------\n|";
	for (int i = INDEX; i <= NICKNAME; i++) {
		searchPrt(Contact::infoArr[i]);
		if (i == NICKNAME)
			std::cout << "\n";
	}
	std::cout << "---------------------------------------------\n";

	// prt all Infos
	while (++idx < 8) {
		if (!contactArr[idx].getFilled())
			break;
		contactArr[idx].prtInfos();
	}

	// CHOOSE INDEX
	std::cout << "CHOOSE SINGLE INDEX\n";
	while (true) {
		std::cout << "[SEARCH] :";
		getline(std::cin, input);
		if (std::cin.eof())
			handleEOF();
		else if (input == "")
			std::cout << "fill out input"
					  << "\n";
		if (input.length() > 1 || !std::isdigit(input[0])) {
			std::cout << "Invalid input try again\n";
			continue;
		} else if ((input[0] - '0') < 0 || (input[0] - '0') >= idx)
		{
			std::cout << "out of range try again\n";
			continue ;
		}
		if (!input.empty())
		{
			idx = input[0] - '0';
			break;
		}
	}
	
	// PRT DETAIL INFOS
	std::cout << "\n     DETAILED INFO ABOUT CONTACT\n\n";
	contactArr[idx].prtDetailInfos();	
}