/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:18:57 by jgo               #+#    #+#             */
/*   Updated: 2023/04/30 20:48:50 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef UTILS_H
#define UTILS_H

t_command convertStringToCmd(std::string input);
void handleEOF();
void searchPrt(std::string str);
void detailPrt(std::string key, std::string val);
bool isPhoneNumber(const std::string& str);

#endif