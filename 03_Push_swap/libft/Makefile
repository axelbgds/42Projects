NAME =	libft.a

SRCS = 	ft_atoi.c ft_isdigit.c ft_strlen.c ft_memset.c ft_bzero.c \
	ft_strchr.c ft_strncmp.c ft_calloc.c ft_strdup.c \
	ft_memcpy.c ft_substr.c ft_strjoin.c ft_split.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	get_next_line.c get_next_line_utils.c \

SRCS_BONUS = 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c \

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
