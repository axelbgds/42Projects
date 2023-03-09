CC = gcc

DIR_SRC = src/
DIR_OBJ = obj/

SRCS=$(shell find $(DIR_SRC) -type f)

INCLUDES=-Iinclude

CFLAGS=-Wall -Werror -Wextra $(INCLUDES)

NAME=03_push_swap

OBJS=$(patsubst $(DIR_SRC)/%,$(DIR_OBJ)/%,$(SRCS:.c=.o))

all: $(NAME)

re : fclean all

clean:
	rm -rf $(DIR_OBJ)

fclean:
	rm -rf ${NAME}

$(NAME): $(OBJS)
	# $(CC) -o $@ $^ $(LDFLAGS)

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c
	echo === 'toto' $@
    # mkdir -p $(dir $@)
    # $(CC) -o $@ -c $< $(CFLAGS)

run: all
	./push_swap `ruby -e "puts (-5000..5000).to_a.reverse.insert(rand(8000) + 1000, 10001).join(' ')"` | wc -l
	./push_swap `ruby -e "puts (-1000..1000).to_a.shuffle.join(' ')"` | wc -l

.PHONY: clean fclean re all $(NAME)
