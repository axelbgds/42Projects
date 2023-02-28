# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 13:34:16 by abeaugra          #+#    #+#              #
#    Updated: 2023/02/20 16:40:46 by abeaugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap.a

SRCS =	parsing.c stack_ope1.c stack_ope2.c chain_list_func.c \
		sort_push_swap.c \

OBJS =		$(SRCS:.c=.o)

RM =		rm -f
CFLAGS =	-Wall -Wextra -Werror

all:		$(NAME)
$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)
bonus :		$(OBJS) $(OBJS_BONUS)
		ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)
clean :
		$(RM) $(OBJS) $(OBJS_BONUS)
fclean :	clean
			$(RM) $(NAME)
re :		fclean $(NAME)
