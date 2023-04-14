# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 10:39:29 by abeaugra          #+#    #+#              #
#    Updated: 2023/04/05 13:16:07 by abeaugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Werror -Wextra -Wall
NAME	= pipex

SRC_PATH = src/
OBJ_PATH = obj/

SRC	= env_parsing.c \
	file_handler.c \
	ft_memcpy.c \
	ft_put_utils.c \
	ft_split.c \
	ft_str_utils1.c \
	ft_str_utils2.c \
	ft_substr.c \
	init.c \
	pipex.c \
	utils.c \
	get_next_line.c \
	get_next_line_utils.c
	
# SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

INC		= -I ./includes/

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)get_next_line/
	@ $(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	@ $(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "Make Succesfull"

bonus: all

clean:
	@rm -rf $(OBJ_PATH)
	@echo "rm -rf obj/ Succesfull"

fclean: clean
	@rm -f $(NAME)
	@echo "rm -f pipex Succesfull"

re: fclean all

.PHONY: all re clean fclean