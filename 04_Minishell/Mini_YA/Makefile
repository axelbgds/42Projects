# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 10:53:07 by abeaugra          #+#    #+#              #
#    Updated: 2023/07/25 14:26:27 by abeaugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCS = main.c
OBJS = $(SRCS:.c=.o)
CC = @gcc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
SRC_DIR = srcs/

SRC_1 = srcs/minishell.c
SRC_2 = srcs/exec/read_command.c \

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

INCLUDE = -L ./libft -lft

$(NAME): $(OBJ_1) $(OBJ_2) credit
	@make -C $(LIBFTDIR)
	${CC} ${CFLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}
	@echo "\033[32mMandatory files compiled successfully ✅\033[32m\n"

all: $(NAME)

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@echo "\033[32mClean repository successfully ✅\033[32m\n"

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@echo "\033[32mFclean repository successfully ✅\033[32m\n"

re: fclean all

.PHONY: all clean fclean re

credit:
	@echo "        .__       .__       .__           .__  .__  	"
	@echo "  _____ |__| ____ |__| _____|  |__   ____ |  | |  |  "
	@echo " /     \|  |/    \|  |/  ___/  |  \_/ __ \|  | |  |  "
	@echo "|  Y Y  \  |   |  \  |\___ \|   Y  \  ___/|  |_|  |__"
	@echo "|__|_|  /__|___|  /__/____  >___|  /\___  >____/____/"
	@echo "      \/        \/        \/     \/     \/           "
	@echo "    \033[33m   Minishell by: @ybahjaou & @abeaugra \033[33m"
