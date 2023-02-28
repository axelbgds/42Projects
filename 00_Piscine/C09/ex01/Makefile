CC ?= gcc
CFLAGS = -Wall -Wextra -Werror -I./includes/
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
NAME = libft.a

all: ${NAME}

re: fclean all

fclean: clean
	rm -f libft.a

clean: 
	rm -f ${OBJS}

${NAME}: ${OBJS}
	ar -rc libft.a ${OBJS}
	ranlib libft.a

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

%.c: $(shell find ./includes/ -name "*.h")

.PHONY: all clean fclean re
