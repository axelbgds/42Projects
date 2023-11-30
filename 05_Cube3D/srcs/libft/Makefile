# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 15:57:37 by alsaez            #+#    #+#              #
#    Updated: 2023/04/27 15:38:31 by alsaez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

INCLUDE = libft.h

SRC = ft_atoi.c \
      	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_split.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	printf/ft_print_char.c \
	printf/ft_print_convert.c \
	printf/ft_print_hexa.c \
	printf/ft_print_int.c \
	printf/ft_print_prc.c \
	printf/ft_print_ptr.c \
	printf/ft_print_str.c \
	printf/ft_print_uint.c \
	printf/ft_printf.c \
	printf/ft_treat_flags.c \
	printf/ft_treat_flags2.c \
	printf/ft_treat_min_int.c \
	printf/ft_treatment.c \
	get_next_line/gnlutil2.c \
	get_next_line/gnl2.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	@ar rc ${NAME} ${OBJ}
	@echo "${NAME} created"
	@ranlib ${NAME}
	echo "${NAME} indexed"

%.o: %.c
	@gcc ${FLAGS} -c $< -o $@

clean:
	@rm -f ${OBJ}
	@echo "Objects deleted"

fclean: clean
	@rm -f ${NAME}
	@echo "${NAME} deleted"

re: fclean all

.PHONY: all clean re
