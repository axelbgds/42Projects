NAME 			= push_swap
CFLAGS			= -Wall -Wextra -Werror

# ----------------------------------------------------------------------------- #

inc_dir 		= includes/ 	# go to .h
func			= func/			# go to function, ope stack, parsing
srt_dir 		= sort_stack/ 	# go to sort algo
checker_dir 	= checker_src/	# checker with GNL and pars

# ----------------------------------------------------------------------------- #

FUNC 			= function_stack1.c function_stack2.c parsing.c stack_ope1.c stack_ope2.c

SORT 			= sort_vsm.c sort_small.c sort_middle.c sort_big.c

CHECKER 		= mainc.c get_next_line.c get_next_line_utils.c

# ----------------------------------------------------------------------------- #

OBJS 		= $(SRCS:.c=.o)
RM			= rm -f

# ----------------------------------------------------------------------------- #

all 		: $(NAME)
$(NAME) 	:
	CFLAGS -o $(NAME) srcs/main.c 	$(addprefix $(func), $(FUNC))
									$(addprefix $(srt_dir), $(SORT))

bonus :	$(NAME)
	CFLAGS -o checker $(NAME)	 	$(addprefix $(checker_dir), $(CHECKER))
									$(addprefix $(func), $(FUNC))
									$(addprefix $(srt_dir), $(SORT))

clean :		
		$(RM) $(OBJS)
		$(RM) checker

fclean :	clean
			$(RM) $(NAME)

re :		fclean all

