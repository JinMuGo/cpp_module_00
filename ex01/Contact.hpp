/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:26:25 by jgo               #+#    #+#             */
/*   Updated: 2023/05/02 14:02:36 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "main.h"

class Contact {
   private:
	std::string info_[6];
	bool filled_;

   public:
	Contact();
	~Contact();
	void saveColumn(int info);
	void saveInfo(int idx);
	void prtInfos(void);
	void prtDetailInfos(void) const;
	std::string formatStr(std::string str);
	static const std::string infoArr[6];
	bool getFilled(void) const;
};

#endif