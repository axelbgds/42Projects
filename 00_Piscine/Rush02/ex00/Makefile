NAME ?= rush-02
CC ?= gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(shell find ./src -name "*.c")
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${@}

%.o: %.c
	${CC} ${CFLAGS} -c ${<} -o ${@}

re: fclean all

fclean: clean
	rm -f ${NAME}

clean:
	rm -f ${OBJS}

.PHONY: clean fclean re all
