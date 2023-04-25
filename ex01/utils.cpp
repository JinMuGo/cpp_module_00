/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:17:20 by jgo               #+#    #+#             */
/*   Updated: 2023/04/23 15:46:14 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_command convertString(std::string input) {
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
