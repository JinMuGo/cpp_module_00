/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:17:20 by jgo               #+#    #+#             */
/*   Updated: 2023/04/30 20:56:32 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_command convertStringToCmd(std::string input) {
	if (input == "EXIT")
		return (EXIT);
	else if (input == "ADD")
		return (ADD);
	else if (input == "SEARCH")
		return (SEARCH);
	else
		return (NONE);
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

	std::cout << "     " << std::setw(WIDTH) << std::left << key << ": ";
	std::cout << val << "\n";
}

bool isPhoneNumber(const std::string& str) {
	std::regex reg("[[:digit:]]{3}-[[:digit:]]{4}-[[:digit:]]{4}");
	std::string::const_iterator it = str.begin();

	if (std::regex_match(str, reg))
		return (true);
	while (it != str.end() && std::isdigit(*it))
		++it;
	return ((!str.empty() && it == str.end()));
}
