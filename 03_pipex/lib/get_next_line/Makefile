NAME = libgnl.a
BONUS_NAME = libbonusgnl.a
CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror -I $(HDR_DIR)
SRC_DIR = ./src/
OBJ_DIR = ./obj/
HDR_DIR = ./include/

SRC =	get_next_line_utils.c\
		get_next_line.c

BONUS_SRC =	get_next_line_utils_bonus.c\
			get_next_line_bonus.c

OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)
BONUS_OBJ = $(BONUS_SRC:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(AR) rcs $@ $(OBJ)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_DIR) $(BONUS_OBJ)
	@$(AR) rcs $@ $(BONUS_OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $(CFLAGS) $^ -o $@

$(OBJ_DIR):
	@mkdir ./obj

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re

