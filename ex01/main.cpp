/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:50:05 by jgo               #+#    #+#             */
/*   Updated: 2023/04/30 20:59:13 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.h"

int main(void) {
	t_command command = DEFAULT;
	PhoneBook phoneBook;
	std::string input;

	while (command) {
		std::cout << "you can choose in (ADD,SEARCH,EXIT)\n";
		std::cout << "[PhoneBook]: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			handleEOF();
			continue;
		}
		command = convertStringToCmd(input);
		switch (command) {
			case ADD:
				phoneBook.addContact();
				break;
			case SEARCH:
				phoneBook.searchContact();
				break;
			case EXIT:
				std::cout << "byebye :)" << std::endl;
				return (0);
			default:
				break;
		}
	}
	return (0);
}