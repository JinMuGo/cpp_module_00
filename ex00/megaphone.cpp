/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:21:18 by jgo               #+#    #+#             */
/*   Updated: 2023/04/29 11:34:30 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define MEGAPHONE_NOISE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int ac, char** av) {
	if (ac == 1)
		std::cout << MEGAPHONE_NOISE;
	else {
		for (int i = 1; av[i]; i++) {
			for (int j = 0; av[i][j]; j++)
				av[i][j] = std::toupper(av[i][j]);
			std::cout << av[i];
		}
	}
	std::cout << std::endl;
	return (0);
}
