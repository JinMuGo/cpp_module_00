/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:21:13 by jgo               #+#    #+#             */
/*   Updated: 2023/05/02 14:55:35 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.h"

const std::string Contact::infoArr[6] = {
	"INDEX", "FIRST_NAME", "LAST_NAME", "NICKNAME", "PHONE_NUMBER", "SECRET"};

Contact::Contact() {
	for (int i = kIndex; i <= kSecret; i++)
		info_[i] = std::string(1, '\0');
	this->filled_ = false;
}

Contact::~Contact() {}

bool Contact::getFilled(void) const{
	return (this->filled_);
}

std::string Contact::formatStr(std::string str) {
	str.replace(WIDTH - 1, std::string::npos, ".");
	str.substr(WIDTH);
	return (str);
}

void Contact::prtInfos(void) {
	std::cout << "|";
	for (int i = kIndex; i <= kNickName; i++) {
		if (info_[i].length() >= WIDTH)
			searchPrt(formatStr(info_[i]));
		else
			searchPrt(info_[i]);
		if (i == kNickName)
			std::cout << "\n";
	}
	std::cout << "---------------------------------------------\n";
}

void Contact::prtDetailInfos(void) const{
	for (int i = kIndex; i <= kSecret; i++)
		detailPrt(infoArr[i], info_[i]);
	std::cout << std::endl;
}

void Contact::saveColumn(int info) {
	const std::string column = infoArr[info];
	std::string input = "";

	while (true) {
		std::cout << "[ADD] " << column << ": ";
		getline(std::cin, input);
		if (std::cin.eof())
			handleEOF();
		else if (input == "")
			std::cout << "fill out input"
					  << "\n";
		else if (column == infoArr[kPhoneNumber] && !isPhoneNumber(input)) {
			std::cout << "PHONE_NUMBER IS MUST BE NUMBER OF LIST \n";
			continue;
		}
		if (!input.empty())
			break;
	}
	this->info_[info] = input;
	std::cout << "Successfully Add : \"" << input << "\" in " << column << "\n";
	this->filled_ = true;
}

void Contact::saveInfo(int idx) {
	std::stringstream ss;
	ss << idx;

	this->info_[kIndex] = ss.str();
	for (int i = kFirstName; i <= kSecret; i++)
		this->saveColumn(i);
	std::cout << "saveInfo in Contact " << idx << std::endl;
}
