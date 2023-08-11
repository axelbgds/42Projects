# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 13:52:46 by tde-los-          #+#    #+#              #
#    Updated: 2023/03/01 13:48:15 by tde-los-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printstr.c ft_putnbr.c

OBS = $(SRCS:.c=.o)

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -c
RM	= rm -f

NAME	= libftprintf.a

.c.o:	$(CC) $(CFLAGS) $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME): $(OBS)
	ar rcs $(NAME) $(OBS)

clean:
	$(RM) $(OBS)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)
