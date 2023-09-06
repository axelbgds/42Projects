NAME := philo
CC := gcc -pthread
CFLAGS := -Wall -Wextra -Werror
SRC := $(wildcard *.c)
OBJS := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Building $(NAME)..."
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@echo "$(NAME) built successfully ✅"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)
	@echo "Object files cleaned ❌"
	@clear

fclean: clean
	@echo "Cleaning $(NAME)..."
	@rm -rf $(NAME)
	@echo "$(NAME) cleaned ❌"
	@clear

re: fclean all

norm:
	@echo "Running norminette..."
	@norminette *.h *.c
	@echo "Norminette check completed."

.PHONY: all clean fclean re norm
