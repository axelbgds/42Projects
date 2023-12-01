# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 13:18:17 by abeaugra          #+#    #+#              #
#    Updated: 2023/10/29 15:22:07 by abeaugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= account
CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf
SRCS	= $(wildcard *.cpp)
OBJS	= $(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -I./ -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;33mCompilation"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32mCompilation reussie"

clean:
	@echo "\033[0;31mDeleting OBJS"
	$(RM) $(OBJS)
	@echo "\033[0;32mDone"

fclean: clean
	@echo "\033[0;31mDeleting NAME"
	$(RM) $(NAME)
	@echo "\033[0;32mDone"

re : fclean all
