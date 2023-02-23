# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaugra < abeaugra@student.42perpignan    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 16:56:17 by abeaugra          #+#    #+#              #
#    Updated: 2023/02/16 17:01:04 by abeaugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= \

CFLAGS		= -Wall -Werror -Wextra
OBJS		= ${NAME:.c=.o}
NAME		= push_swap.a

ERASE		=	\033[2K\r
BLUE		=	\033[34m
YELLOW		=	\033[33m
GREEN		=	\033[32m
END			=	\033[0m

all:		libft $(NAME) checker

$(NAME):	$(P_OBJS)
	$(CC) $(P_OBJS) $(FLAGS) -o $@
	printf "$(ERASE)$(GREEN)$@ made\n$(END)"

checker:	$(C_OBJS)
	$(CC) $(C_OBJS) $(FLAGS) -o $@
	printf "$(ERASE)$(GREEN)$@ made\n$(END)"

libft:
	make -C libft

clean:
	printf "$(YELLOW)$(DIR_OBJS) removed$(END)\n"
	rm -rdf $(DIR_OBJS)
	printf "libft : "
	make clean -C libft

fclean:		clean
	printf "$(YELLOW)$(NAME) removed$(END)\n"
	rm -rf $(NAME) checker
	printf "libft : "
	make fclean -C libft

re:			fclean all