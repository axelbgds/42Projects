NAME = push_swap

NAME_B = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address 

SRCS = ft_cro.c size.c main.c pr_arg.c push.c \
		rotate.c rrotate.c size_3.c size_5.c swap.c sorting_lis.c \
		push_b_utils.c

BSRCS = main_bonus.c pr_arg.c push.c swap.c rotate.c rrotate.c ft_cro.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)


all: $(NAME)

bonus : $(NAME_B)

Libft/libft.a:
	make bonus -C Libft

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $<



$(NAME):$(OBJS) Libft/libft.a push_swap.h Libft/libft.h $(BON)
	$(CC) $(CFLAGS) $(OBJS) Libft/libft.a -o $(NAME)

$(NAME_B): $(BOBJS) Libft/libft.a push_swap.h
	$(CC) $(CFLAGS) $(BOBJS) Libft/libft.a -o $(NAME_B)

clean:
	rm -f $(OBJS) $(BOBJS)
	make clean -C Libft

fclean: clean 
	rm -f $(NAME)
	make fclean -C Libft
	rm -rf $(NAME_B)

re: fclean all 

.PHONY: clean fclean re all
