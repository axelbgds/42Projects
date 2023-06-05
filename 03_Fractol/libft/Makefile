# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 11:44:20 by abeaugra          #+#    #+#              #
#    Updated: 2023/06/05 11:44:30 by abeaugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_atod.c \
		  ft_isdouble.c \
		  ft_itoa.c \
		  ft_printf.c \
		  ft_strjoin.c \
		  ft_strlen.c \
		  ft_strncmp.c \

OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

CC		= gcc

RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}
			ranlib $(NAME)

all:		${NAME}

clean:
			${RM} ${SRCS:.c=.o}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY: 	all clean fclean re .c.o
