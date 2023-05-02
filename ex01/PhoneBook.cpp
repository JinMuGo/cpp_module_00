/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:21:14 by jgo               #+#    #+#             */
/*   Updated: 2023/05/02 14:58:45 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.h"

PhoneBook::PhoneBook() : curIdx(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
	if (curIdx == 8)
		curIdx = 0;
	contactArr[curIdx].saveInfo(curIdx);
	curIdx++;
}

void PhoneBook::searchContact() {
	std::string input;
	int idx = -1;

	// PRT COLUMN
	std::cout << "---------------------------------------------\n|";
	for (int i = kIndex; i <= kNickName; i++) {
		searchPrt(Contact::infoArr[i]);
		if (i == kNickName)
			std::cout << "\n";
	}
	std::cout << "---------------------------------------------\n";

	// PRT ALL INFOS
	while (++idx < 8) {
		if (!contactArr[idx].getFilled())
			break;
		contactArr[idx].prtInfos();
	}

	if (idx == 0) {
		std::cout << "PhoneBook is Empty fill out the first one" << std::endl;
		return;
	}

	// CHOOSE kIndex
	std::cout << "CHOOSE SINGLE kIndex\n";
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
		} else if ((input[0] - '0') < 0 || (input[0] - '0') >= idx) {
			std::cout << "out of range try again\n";
			continue;
		}
		if (!input.empty()) {
			idx = input[0] - '0';
			break;
		}
	}

	// PRT DETAIL INFOS
	std::cout << "\n     DETAILED INFO ABOUT CONTACT\n\n";
	contactArr[idx].prtDetailInfos();
}