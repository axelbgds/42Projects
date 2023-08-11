# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 11:43:23 by abeaugra          #+#    #+#              #
#    Updated: 2023/07/25 15:28:40 by abeaugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
			ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
			ft_tolower.c ft_toupper.c ft_putendl_fd.c ft_striteri.c get_next_line.c \
			ft_lstnew.c ft_lstmap.c ft_lstlast.c ft_lstadd_front.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c
			
OBJS    = $(SRCS:.c=.o)
# BONUS_OBJS = $(BONUS_SRCS:.c=.o)
HDRS    = libft.h
NAME    = libft.a
RM  = @rm -rf
GCC = @gcc
AR  = ar -crs
FLAGS   = -Wall -Wextra -Werror

NO_COLOR = \033[0;39m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
CYAN = \033[0;96m

.SILENT:

.c.o:
		$(GCC) $(FLAGS) -c $< -o $(<:.c=.o) 

$(NAME):	$(OBJS) $(HDRS)
			$(AR) $(NAME) $(OBJS)
			@echo "$(GREEN)libft compiled!$(DEF_COLOR)"

all:	$(NAME)
		
# bonus:	$(OBJS) $(BONUS_OBJS) $(HDRS)
# 		@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
# 		@echo "$(GREEN)libft BONUS compiled!$(DEF_COLOR)"

re:		clean fclean all
		@echo "$(GREEN)libft RE compiled!$(DEF_COLOR)"

# clean:
# 		@$(RM) $(OBJS) $(BONUS_OBJS)
# 		@echo "$(BLUE)libft object files cleaned!$(DEF_COLOR)"

clean:
		@$(RM) $(OBJS)
		@echo "$(BLUE)libft object files cleaned!$(DEF_COLOR)"

fclean:	clean
		@$(RM) $(NAME)
		@echo "$(BLUE)libft executable files cleaned!$(DEF_COLOR)"
.PHONY:
		all clean fclean re bonus
