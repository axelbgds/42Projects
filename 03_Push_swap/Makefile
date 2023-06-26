# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 13:48:18 by abeaugra             #+#    #+#              #
#    Updated: 2023/06/22 12:16:41 by abeaugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = @gcc
RM = @rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
BONUS = checker
SRC_DIR = srcs/

SRC_1 = srcs/push_swap/push_swap.c \

SRC_2 =	srcs/push_swap/algo.c \
		srcs/push_swap/check_args_utils.c \
		srcs/push_swap/check_args.c \
		srcs/push_swap/ef.c \
		srcs/push_swap/parse.c \
		srcs/push_swap/rotate_and_push.c \
		srcs/push_swap/rotate_type.c \
		srcs/push_swap/sort_big.c \
		srcs/push_swap/sort_three.c \
		srcs/push_swap/stack_ope.c \
		srcs/push_swap/lst_utils_2.c \
		srcs/push_swap/lst_utils.c \
		srcs/push_swap/operations_1.c \
		srcs/push_swap/operations_2.c \
		srcs/push_swap/operations_3.c \
		srcs/push_swap/solver_utils_ab.c \
		srcs/push_swap/solver_utils_ba.c \

BONUS_SRC = srcs/checker/checker.c \
			srcs/checker/checker_utils.c \

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}

INCLUDE = -L ./libft -lft

${NAME}: ${OBJ_1} ${OBJ_2} credit
	@make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}
	@echo "\033[32mMandatory files compiled successfully ✅\033[32m\n"

${BONUS}: ${OBJ_2} ${BONUS_OBJ} 
	@make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS} ${INCLUDE}

all: ${NAME} ${BONUS}

bonus: ${BONUS} 
	@echo "\033[32mBonus files compiled successfully ✅\033[32m\n"
	
clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@echo "\033[32mObject files compiled successfully ✅\033[32m\n"

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@echo "\033[32mAll files deleted successfully ✅\033[32m\n"

re: clean all

credit:
	@echo "\n"
	@echo "░▒█▀▀█░▒█░▒█░▒█▀▀▀█░▒█░▒█░░░▒█▀▀▀█░▒█░░▒█░█▀▀▄░▒█▀▀█"
	@echo "░▒█▄▄█░▒█░▒█░░▀▀▀▄▄░▒█▀▀█░░░░▀▀▀▄▄░▒█▒█▒█▒█▄▄█░▒█▄▄█"
	@echo "░▒█░░░░░▀▄▄▀░▒█▄▄▄█░▒█░▒█░░░▒█▄▄▄█░▒▀▄▀▄▀▒█░▒█░▒█░░░\n"
	@echo "     \033[0;96m       Made by : abeaugra \033[0;96m"

.PHONY: all clean fclean re bonus