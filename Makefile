# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 16:45:59 by kyacini           #+#    #+#              #
#    Updated: 2022/12/26 19:11:22 by kyacini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c \
		parsing.c \
		moves_a.c \
		moves_b.c \
		init_stacks.c \
		utils.c \
		algo.c \
		case_man.c

SRC_BONUS = bonus/instruction.c \
			bonus/moves_1.c \
			bonus/moves_2.c \
			bonus/parsing.c \
			bonus/utils.c \
			bonus/main.c \
			bonus/gnl/get_next_line.c \
			bonus/gnl/get_next_line_utils.c

NAME = push_swap
CHECKER = ./bonus/checker

OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}

LIB = ./libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all	:	${NAME} ${LIB}

%.o : %.c
	gcc -o $@ -c $< ${CFLAGS}

${NAME}	:	${OBJS}
	${MAKE} -C ./libft bonus
	${CC} ${OBJS} -o ${NAME} ${LIB} ${CFLAGS} 
	

bonus : ${OBJS_BONUS}
	
	${MAKE} -C ./libft bonus
	${CC} ${OBJS_BONUS} -o ${CHECKER} ${LIB} ${CFLAGS}

clean	:
	${MAKE} -C ./libft clean
	rm -rf ./bonus/*.o
	rm -rf ./bonus/gnl/*.o
	rm -rf *.o

fclean	:	clean
	${MAKE} -C ./libft fclean
	rm -rf ${NAME}
	
re:	fclean all
