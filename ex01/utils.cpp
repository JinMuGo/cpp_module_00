/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:17:20 by jgo               #+#    #+#             */
/*   Updated: 2023/05/02 14:59:15 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_command convertStringToCmd(std::string input) {
	if (input == "EXIT")
		return (kExit);
	else if (input == "ADD")
		return (kAdd);
	else if (input == "SEARCH")
		return (kSearch);
	else
		return (kNone);
}

void handleEOF() {
	std::cout << "EOF detected. write again"
			  << "\n";
	std::cin.clear();
	clearerr(stdin);
}

void searchPrt(std::string str) {
	std::cout << std::setw(WIDTH) << std::right << str << "|";
}

void detailPrt(std::string key, std::string val) {

	std::cout << "     " << std::setw(WIDTH + 5) << std::left << key << ": ";
	std::cout << val << "\n";
}

bool isPhoneNumber(const std::string& str) {
	std::string::const_iterator it = str.begin();

	while (it != str.end() && std::isdigit(*it))
		++it;
	return ((str.length() == 11 && !str.empty() && it == str.end()));
}
