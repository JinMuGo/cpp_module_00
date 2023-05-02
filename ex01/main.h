/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:43:21 by jgo               #+#    #+#             */
/*   Updated: 2023/05/02 14:55:11 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <sstream>

# define WIDTH 10

enum e_command {
	kExit,
	kNone,
	kDefault,
	kAdd,
	kSearch,
};

enum e_info {
	kIndex,
	kFirstName,
	kLastName,
	kNickName,
	kPhoneNumber,
	kSecret
};

typedef enum e_command t_command;
typedef enum e_info t_info;

#endif