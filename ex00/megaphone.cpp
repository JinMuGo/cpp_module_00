/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:21:18 by jgo               #+#    #+#             */
/*   Updated: 2023/05/03 11:28:02 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char** av) {
	const std::string kMegaPhoneNoise =
		"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::string str;

	if (ac == 1)
		std::cout << kMegaPhoneNoise;
	else {
		for (int i = 1; i < ac; ++i) {
			str = av[i];
			for (std::string::iterator it = str.begin(); it != str.end();
				 ++it) {
				*it = std::toupper(*it);
			}
			std::cout << str;
		}
	}
	std::cout << std::endl;
	return (0);
}
