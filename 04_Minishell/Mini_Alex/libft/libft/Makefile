# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 11:20:15 by tde-los-          #+#    #+#              #
#    Updated: 2023/02/14 10:58:36 by tde-los-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalnum.c ft_isprint.c ft_memmove.c ft_putnbr_fd.c ft_strjoin.c ft_strncmp.c \
	  ft_tolower.c ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_putstr_fd.c \
	  ft_strlcat.c ft_strnstr.c ft_toupper.c ft_bzero.c ft_isascii.c ft_memcmp.c \
	  ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_calloc.c ft_isdigit.c \
	  ft_memcpy.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_substr.c ft_strtrim.c \
	  ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c

OBS	= $(SRCS:.c=.o)

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -c
RM	= rm -f

NAME	= libft.a

.c.o:	$(CC) $(CFLAGS) $< -o $(<:.c=.o)

all:	 $(NAME)

$(NAME): $(OBS)
	ar rcs $(NAME) $(OBS)

clean:
	$(RM) $(OBS)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)
