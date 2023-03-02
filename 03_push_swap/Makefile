NAME 			= push_swap
CFLAGS			= -Wall -Wextra -Werror

# ----------------------------------------------------------------------------- #

inc_dir 		= includes/ 	# go to .h
stack_ope_dir	= stack_ope/	# go to operation stack
srt_dir 		= sort_stack/ 	# go to sort function
pars_dir		= pars_dir/		# go to pars
checker_dir 	= checker_src/	# checker with GNL and pars

# ----------------------------------------------------------------------------- #

STACK 			= function_stack.c stack_ope1.c stack_ope2.c

SORT 			= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c parsing.c

PARS 			= parsing.c

CHECKER 		= mainc.c get_next_line.c get_next_line_utils.c

# ----------------------------------------------------------------------------- #

OBJS 		= $(SRCS:.c=.o)
# OBJS_BONUS 	= $(SRCS_BONUS:.c=.o)
RM			= rm -f

# ----------------------------------------------------------------------------- #

all 		: $(NAME)
$(NAME) 	:
	CFLAGS -o $(NAME) srcs/main.c 	$(addprefix $(stack_ope_dir), $(STACK))
									$(addprefix $(srt_dir), $(SORT))
									$(addprefix $(pars_dir), $(PARS))

bonus :	$(NAME)
	CFLAGS -o checker $(NAME)	 	$(addprefix $(checker_dir), $(CHECKER))
									$(addprefix $(stack_ope_dir), $(STACK))
									$(addprefix $(srt_dir), $(SORT))
									$(addprefix $(pars_dir), $(PARS))

clean :		
		$(RM) $(OBJS)
		$(RM) checker

fclean :	clean
			$(RM) $(NAME)

re :		fclean all

