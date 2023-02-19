# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 17:02:13 by aaoutem-          #+#    #+#              #
#    Updated: 2023/02/19 16:16:01 by aaoutem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror 
FLAGS_ = -lmlx -Imlx -Lmlx -framework OpenGL -framework AppKit
RM = rm -rf
HEADER = so_long.h
SRCS =	main.c map_to_graphics.c get_next_line.c get_next_line_utils.c \
	ft_split.c moves.c map_rendering.c ft_itoa.c ft_putnbr.c map_parsing.c\
	backtrack.c 
OBJ_F = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJ_F}
	${CC} ${FLAGS} ${FLAGS_} ${OBJ_F} -o so_long
%.o : %.c 
	${CC} ${FLAGS} -c $< -o $@ 


# NAME : ${OBJ_F}
# 	${CC} ${FLAGS} ${OBJ_F} ${FLAGS_} -o so_long

# %.o : %.c 
#	${CC} ${FLAGS} -c $< -o $@ ${FLAGS_}

# ${CC} $< ${FLAGS} ${FLAGS_}  -c

# graphics.c get_next_line.c get_next_line_utils.c\
# 		ft_putnbr.c ft_split.c map_rendering.c
clean :
	${RM} ${OBJ_F}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re