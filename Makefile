# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 17:02:13 by aaoutem-          #+#    #+#              #
#    Updated: 2023/02/14 23:28:21 by aaoutem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextar -Werror -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
Headers = so_long.h
SRCS = graphics.c get_next_line.c get_next_line_utils.c\
		ft_putnbr.c ft_split.c map_rendering.c
