SRCS		= $(addprefix srcs/, actions.c \
		  algorithms.c \
		  main.c)

BONUS_SRCS	= $(addprefix srcs/, actions_bonus.c \
		  algorithms_bonus.c \
		  main_bonus.c)

ifndef WITH_BONUS
	OBJS	= $(SRCS:.c=.o)
else
	OBJS	= $(BONUS_SRCS:.c=.o)
endif

INCS 		= includes/fractol.h

BONUS_INCS 	= includes/fractol_bonus.h

NAME 		= fractol

LIBFT_DIR	= ./libft

LIBFT		= $(LIBFT_DIR)/libft.a

LFLAGS		= -lX11 -lXext -lm -lbsd
# LFLAGS		= -L -lft -lmlx -lXext -lX11 -lm
CC		= gcc

RM		= rm -rf

CFLAGS		= -Wall -Wextra -Werror -O3

.c.o:
		@${CC} $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(LIBFT):
		@/bin/echo -n "$(shell tput bold)$(shell tput setaf 165)Compiling Libft: $(shell tput sgr0)"
			@make -sC $(LIBFT_DIR) > /dev/null
		@echo "$(shell tput bold)$(shell tput setaf 46)[OK]$(shell tput sgr0)"

$(NAME):	$(OBJS) $(LIBFT)
		@/bin/echo -n "$(shell tput bold)$(shell tput setaf 165)Compiling \"$(NAME)\": $(shell tput sgr0)"
			@${CC} $(CFLAGS) $(OBJS) $(LIBFT) minilix/libmlx.a $(LFLAGS) -o $(NAME)
		@echo "$(shell tput bold)$(shell tput setaf 46)[OK]$(shell tput sgr0)"
			@make -s norminette

bonus:
		@if [ -e srcs/actions.o -a -e srcs/algorithms.o -a -e srcs/main.o \
			-a -e srcs/actions_bonus.o -a -e srcs/algorithms_bonus.o -a -e srcs/main_bonus.o -a -e fractol ]; then \
			rm srcs/actions_bonus.o && rm srcs/algorithms_bonus.o && rm srcs/main.o && rm fractol; \
		fi
			@make WITH_BONUS=1 all --no-print-directory
			@${RM} $(SRCS:.c=.o)
norminette:
		@if norminette $(SRCS) $(BONUS_SRCS) $(INCS) $(BONUS_INCS) $(LIBFT_DIR) > /dev/null; then \
			echo "$(shell tput setaf 190)Norminette: $(shell tput setaf 46)[OK]$(shell tput sgr0)"; \
		else \
			echo "$(shell tput setaf 190)Norminette: $(shell tput setaf 196)[KO]$(shell tput sgr0)"; \
		fi
		@sleep 0.2

clean:
		@/bin/echo -n "$(shell tput bold)$(shell tput setaf 196)Deleting project's object files: $(shell tput sgr0)"
			@${RM} $(SRCS:.c=.o) $(BONUS_SRCS:.c=.o)
		@echo "$(shell tput bold)$(shell tput setaf 46)[OK]$(shell tput sgr0)"
		@/bin/echo -n "$(shell tput bold)$(shell tput setaf 196)Deleting Libft's object files: $(shell tput sgr0)"
			@make clean -sC $(LIBFT_DIR) > /dev/null
		@echo "$(shell tput bold)$(shell tput setaf 46)[OK]$(shell tput sgr0)"

fclean:		clean
		@/bin/echo -n "$(shell tput bold)$(shell tput setaf 196)Deleting \"$(NAME)\": $(shell tput sgr0)"
			@${RM} $(NAME)
		@echo "$(shell tput bold)$(shell tput setaf 46)[OK]$(shell tput sgr0)"
		@/bin/echo -n "$(shell tput bold)$(shell tput setaf 196)Deleting \"libft.a\": $(shell tput sgr0)"
			@${RM} $(LIBFT)
		@echo "$(shell tput bold)$(shell tput setaf 46)[OK]$(shell tput sgr0)"

re:		fclean all

rebonus:	fclean bonus

.PHONY: 	all clean fclean re .c.o bonus rebonus norminette