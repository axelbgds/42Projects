SRCS = $(shell find ./srcs/ -name "*.c")
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror

all: ft_display_file

ft_display_file: ${OBJS}
	gcc ${CFLAGS} -o ${@} ${OBJS}

fclean: clean
	rm -rf ft_display_file

clean:
	rm -rf ${OBJS}

re: fclean all

%.o: %.c
	gcc -c ${@:.o=.c} -o ${@}


