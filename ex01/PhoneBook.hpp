/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:26:36 by jgo               #+#    #+#             */
/*   Updated: 2023/04/23 16:06:00 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

class PhoneBook {
  private:
	Contact	contactArr[8];
	int		curIdx;

  public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact();
};
