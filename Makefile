# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:55:24 by jolecomt          #+#    #+#              #
#    Updated: 2023/10/18 22:54:57 by jolecomt         ###   ########.fr        #
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
	echo "Minitalk is compiled"


client: ${OBJS_CLIENT}
	$(CC) $(FLAGS) ${OBJS_CLIENT} -o client
	echo "The client has been created."

server: ${OBJS_SERVER}
	$(CC) $(FLAGS) ${OBJS_SERVER} -o server
	echo "The server has been created."

clean:
	rm -f ${OBJS_CLIENT}
	rm -f ${OBJS_SERVER}
	echo "All objects from the client and the server have been deleted."

fclean: clean
	rm -f client
	rm -f server
	echo "The client and the server have been deleted."

re: fclean all
	# clear

.PHONY: all clean fclean re

.SILENT:

