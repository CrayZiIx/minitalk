# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:55:24 by jolecomt          #+#    #+#              #
#    Updated: 2023/10/09 14:51:18 by jolecomt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_CLIENT		=	sources/client/client.c		\
				utils/ft_atoi.c			

SRCS_SERVER		=	sources/server/server.c		\
				utils/ft_addchar_tobuff.c	\
				utils/ft_strlen.c		\
				utils/ft_itoa.c

OBJS_CLIENT		=	${SRCS_CLIENT:.c=.o}

OBJS_SERVER		=	${SRCS_SERVER:.c=.o}

CC 			= gcc
FLAGS			= -Wall -Wextra -Werror

all: client server
	make clean
	clear


client: ${OBJS_CLIENT}
	$(CC) $(FLAGS) ${OBJS_CLIENT} -o client

server: ${OBJS_SERVER}
	$(CC) $(FLAGS) ${OBJS_SERVER} -o server

clean:
	rm -f ${OBJS_CLIENT}
	rm -f ${OBJS_SERVER}

fclean: clean
	rm -f client
	rm -f server

re: fclean all

.PHONY: all clean fclean re

.SILENT:

