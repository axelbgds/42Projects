NAME		:= philo
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
SRC			:= $(wildcard *.c)
OBJS		:= $(SRC:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@clear

fclean: clean
	@rm -rf $(NAME)
	@clear

re: fclean all

norm:
	@norminette *.h *.c

.PHONY: all clean fclean re
