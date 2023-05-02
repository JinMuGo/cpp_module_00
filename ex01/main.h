/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:43:21 by jgo               #+#    #+#             */
/*   Updated: 2023/05/01 15:35:53 by jgo              ###   ########.fr       */
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
	EXIT,
	NONE,
	DEFAULT,
	ADD,
	SEARCH,
};

enum e_info {
	INDEX,
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	SECRET
};

typedef enum e_command t_command;
typedef enum e_info t_info;

#endif