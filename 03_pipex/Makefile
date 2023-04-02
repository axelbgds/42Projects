
NAME = pipex
NAME_BONUS = pipex_bonus
NAME_TEST = test
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = ./src/
SRC_DIR_BONUS = ./src_bonus/
SRC_TEST_DIR = ./src_test/
OBJ_DIR = ./obj/
OBJ_DIR_BONUS = ./obj_bonus/
OBJ_TEST_DIR = ./obj_test/

INC_DIR = -I ./inc -I ./lib/libft -I ./lib/get_next_line/include
LIBFT= ./lib/libft/libft.a
LIBGNL = ./lib/get_next_line/libgnl.a

SRC =	pipex.c \
		utils_checks.c \
		utils_cleanup.c \
		utils_help_parse.c \
		utils_parse.c \
		utils_temp.c \
		utils_pipe.c

SRC_BONUS=	pipex_bonus.c \
			utils_checks_bonus.c \
			utils_cleanup_bonus.c \
			utils_help_parse_bonus.c \
			utils_heredoc.c \
			utils_parse_bonus.c \
			utils_pipe_bonus.c \
			utils_temp_bonus.c

SRC_TEST =	utils_checks.c \
			utils_cleanup.c \
			utils_help_parse.c \
			utils_parse.c \
			main.c

OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

OBJ_TEST = $(SRC_TEST:%.c=$(OBJ_TEST_DIR)%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR_BONUS)%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $(CFLAGS) $(INC_DIR) $^ -o $@

$(OBJ_DIR):
	@mkdir -p ./obj

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_DIR_BONUS) $(LIBFT) $(LIBGNL) $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) $(LIBFT) $(LIBGNL) -o $(NAME)

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c
	@$(CC) -c $(CFLAGS) $(INC_DIR) $^ -o $@

$(OBJ_DIR_BONUS):
	@mkdir -p ./obj_bonus

test:

$(NAME_TEST): $(OBJ_TEST_DIR) $(LIBFT) $(LIBGNL) $(OBJ_TEST)
	@$(CC) $(OBJ_TEST) $(LIBFT) $(LIBGNL) -o $(NAME_TEST)

$(OBJ_TEST_DIR)%.o: $(SRC_TEST_DIR)%.c
	@$(CC) -c $(CFLAGS) $(INC_DIR) $^ -o $@

$(OBJ_TEST_DIR):
	@mkdir -p ./obj_test

$(LIBFT):
	@$(MAKE) -C ./lib/libft

$(LIBGNL):
	@$(MAKE) -C ./lib/get_next_line

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@rm -rf $(OBJ_TEST_DIR)
	@make clean -C ./lib/libft
	@make clean -C ./lib/get_next_line

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f $(NAME_TEST)
	@make fclean -C ./lib/libft
	@make fclean -C ./lib/get_next_line

re: fclean all

.PHONY: all clean fclean re bonus
