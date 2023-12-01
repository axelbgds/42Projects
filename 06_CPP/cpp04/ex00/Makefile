# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 13:47:27 by abeaugra          #+#    #+#              #
#    Updated: 2023/11/20 17:28:07 by abeaugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= animal
CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf
SRCS	= $(wildcard *.cpp)
OBJS	= $(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32mCompilation reussie"

clean:
	@$(RM) $(OBJS)
	@echo "\033[0;31mDeleting OBJS Done"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31mDeleting NAME Done"

re : fclean all

