# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 16:45:59 by kyacini           #+#    #+#              #
#    Updated: 2022/09/23 16:56:19 by kyacini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
		parsing.c \
		moves_a.c \
		moves_b.c \
		init_stacks.c \
		utils.c \
		algo.c \
		case_man.c

NAME = push_swap

OBJS = ${SRC:.c=.o}

OBJS_BONUS = ${BONUS:.c=.o}

all	:	${NAME}

%.o : %.c
	gcc -o $@ -c $< 

push_swap	:	${OBJS}
	gcc ${OBJS} -o ${NAME} libft.a

clean	:
	rm -rf *.o

fclean	:	clean
	rm -rf ${NAME}
	
re:	fclean all
