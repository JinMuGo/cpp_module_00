/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:21:13 by jgo               #+#    #+#             */
/*   Updated: 2023/04/29 11:22:41 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.h"

const std::string Contact::infoArr[5] = {"INDEX", "FIRST_NAME", "LAST_NAME",
										 "NICKNAME", "SECRET"};

Contact::Contact() {
	for (int i = INDEX; i <= SECRET; i++)
		info[i] = std::string(1, '\0');
	filled = false;
}

Contact::~Contact() {}

bool Contact::getFilled(void) {
	return (filled);
}

std::string Contact::formatStr(std::string str) {
	str.replace(WIDTH - 1, std::string::npos, ".");
	str.substr(WIDTH);
	return (str);
}

void Contact::prtInfos(void) {
	std::cout << "|";
	for (int i = INDEX; i <= NICKNAME; i++) {
		if (info[i].length() >= WIDTH)
			searchPrt(formatStr(info[i]));
		else
			searchPrt(info[i]);
		if (i == NICKNAME)
			std::cout << "\n";
	}
	std::cout << "---------------------------------------------\n";
}

void Contact::prtDetailInfos(void) {
	for (int i = INDEX; i <= SECRET; i++)
		detailPrt(infoArr[i], info[i]);
	std::cout << std::endl;
}

void Contact::saveColumn(int _info) {
	const std::string column = infoArr[_info];
	std::string input = "";

	while (true) {
		std::cout << "[ADD] " << column << ": ";
		getline(std::cin, input);
		if (std::cin.eof())
			handleEOF();
		else if (input == "")
			std::cout << "fill out input"
					  << "\n";
		if (!input.empty())
			break;
	}
	info[_info] = input;
	std::cout << "Successfully Add : \"" << input << "\" in " << column << "\n";
	filled = true;
}

void Contact::saveInfo(int idx) {
	std::stringstream ss;
	ss << idx;

	this->info[INDEX] = ss.str();
	for (int i = FIRST_NAME; i <= SECRET; i++)
		this->saveColumn(i);
	std::cout << "saveInfo in Contact " << idx << std::endl;
}
