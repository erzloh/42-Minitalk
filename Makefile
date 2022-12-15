# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 08:39:00 by eholzer           #+#    #+#              #
#    Updated: 2022/12/15 16:41:24 by eholzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		=	server
CLIENT		=	client

SRCS_S		=	server.c
SRCS_C		=	client.c

OBJS_S		=	${SRCS_S:.c=.o}
OBJS_C		=	${SRCS_C:.c=.o}

CFLAGS		=	-Wall -Werror -Wextra
CC			=	gcc

LIBFT_DIR	=	libft
LIBFT		=	libft.a

all:		${LIBFT} ${SERVER} ${CLIENT}

${LIBFT}:
			make -C ${LIBFT_DIR}

${SERVER}:	${OBJS_S}
			${CC} ${CFLAGS} -o ${SERVER} ${OBJS_S} ${LIBFT_DIR}/${LIBFT}

${CLIENT}:	${OBJS_C}
			${CC} ${CFLAGS} -o ${CLIENT} ${OBJS_C} ${LIBFT_DIR}/${LIBFT}

clean:
			rm -f ${OBJS_S}
			rm -f ${OBJS_C}
			make -C ${LIBFT_DIR} clean

fclean:		clean
			rm -f ${SERVER}
			rm -f ${CLIENT}
			rm -f ${LIBFT_DIR}/${LIBFT}

re:			fclean re

.PHONY:		all clean fclean re