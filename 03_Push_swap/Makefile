NAME = push_swap

NAME_CHECK = checker

CC = CC

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRC = 	check_arg.c clear_lst.c list_sortb.c list_sorta.c \
		os_push.c os_swap.c os_rev_rot.c os_rotate.c \
		sort_big.c sort_small.c

BSRC = 	main_bonus.c check_arg.c os_push.c os_swap.c os_rotate.c \
		os+os_rev_rot.c

OBJS = $(SRC:.c-.o)

OBJS_BON = $(BSRC:.c-.o)

all: $(NAME)

bonus: $(NAME_B)

libft/libft.a:
	make bonus -C libft

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS) libft/libft.a push_swap.h libft/libft.h $(BON)
	$(CC) $(CFLAGS) $(OBJS_BON) libft/libft.a -o $(NAME_B)

clean:
	rm -f $(OBJS) $(OBJS_BON)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	rm -rf $(NAME_B)

re: fclean all

test2:	$(NAME)	
			$(eval ARG = $(shell shuf -i 0-100 -n 2))
			./push_swap $(ARG) | ./checker_linux $(ARG)
			@echo -n "Instructions: "
			@./push_swap $(ARG) | wc -l

test3:	$(NAME)	
			$(eval ARG = $(shell shuf -i 0-100 -n 3))
			./push_swap $(ARG) | ./checker_linux $(ARG)
			@echo -n "Instructions: "
			@./push_swap $(ARG) | wc -l

test5:	$(NAME)	
			$(eval ARG = $(shell shuf -i 0-5000 -n 5))
			./push_swap $(ARG) | ./checker_linux $(ARG)
			@echo -n "Instructions: "
			@./push_swap $(ARG) | wc -l

test100:	$(NAME)	
				$(eval ARG = $(shell shuf -i 0-5000 -n 100))
				./push_swap $(ARG) | ./checker_linux $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

test500:	$(NAME)	
				$(eval ARG = $(shell shuf -i 0-5000 -n 500))
				./push_swap $(ARG) | ./checker_linux $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

test1000:	$(NAME)	
				$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
				./push_swap $(ARG) | ./checker_linux $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

.PHONY: clean fclean re all test2 test3 test5 test100 test500 test1000