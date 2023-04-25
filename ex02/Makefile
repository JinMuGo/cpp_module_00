# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 19:34:14 by jgo               #+#    #+#              #
#    Updated: 2023/04/23 16:09:27 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../makeConfig/Rules.mk
include ../makeConfig/Color_rules.mk

SRCS :=	Account.cpp \
		tests.cpp

NAME := TheJobOfYourDreams

OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)
-include $(DEPS)

include ../makeConfig/Targets.mk