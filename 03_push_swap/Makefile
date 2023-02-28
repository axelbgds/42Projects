NAME =	push_swap.a

SRCS = 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	parsing.c \

SRCS_BONUS = 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJS 		= $(SRCS:.c=.o)
OBJS_BONUS 	= $(SRCS_BONUS:.c=.o)
RM		= rm -f
CFLAGS		= -Wall -Wextra -Werror

all :		$(NAME)
$(NAME) :	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus : 	$(OBJS_BONUS)
			ar rcs $(NAME) $(OBJS_BONUS)

clean :		
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean :	clean
			$(RM) $(NAME)

re :		fclean $(NAME)

