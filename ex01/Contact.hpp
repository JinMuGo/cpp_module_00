/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:26:25 by jgo               #+#    #+#             */
/*   Updated: 2023/04/23 16:05:53 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.h"

class Contact {
   private:
    std::string info[5];
    bool filled;

   public:
    Contact();
    void saveColumn(int info);
    void saveInfo(int idx);
    void prtInfos(void);
    void prtDetailInfos(void);
    std::string formatStr(std::string str);
    static const std::string infoArr[5];
    bool getFilled();
};