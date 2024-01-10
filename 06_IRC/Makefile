NAME = ircserv
HEADER_SRCS =	Channel.hpp		\
				Color.hpp		\
				ft_irc.hpp		\
				Server.hpp		\
				User.hpp
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))
SRCS_DIR	=	srcs/
SRCS		=	Channel.cpp		\
				Commands.cpp	\
				Error.cpp		\
				Irc_invite.cpp	\
				Irc_kick.cpp	\
				Irc_part.cpp	\
				Irc_privmsg.cpp	\
				Irc_quit.cpp	\
				Irc_topic.cpp	\
				Irc_userhost.cpp\
				main.cpp		\
				Print.cpp		\
				Server.cpp		\
				User.cpp		\
				Utils.cpp
OBJDIR		=	objs
SRCS_PATH	=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJ_SRCS	=	$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
COMPILE		=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -g -Wshadow -Wno-shadow
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"
### RULES ###
all: $(NAME)
$(OBJDIR)/%.o: $(SRCS_DIR)%.cpp $(HEADER) Makefile
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${COMPILE} ${FLAGS} -I./$(HEADER_DIR) -c -o $@ $<
	@printf ${UP}${CUT}
$(NAME): ${OBJ_SRCS}
	@$(COMPILE) ${FLAGS} -o $(NAME) ${OBJ_SRCS}
	@echo $(G)Project FT_IRC ! by JMETEZEA, ABEAUGRA and SDESTANN successfully compiled${X}
clean:
	@echo ${R}Cleaning FT_IRC ! ${G}[${OBJDIR}]...${X}
	@/bin/rm -Rf ${OBJDIR}
fclean: clean
	@echo ${R}FCleaning FT_IRC ! ${G}[${NAME}]...${X}
	@/bin/rm -f ${NAME}
re: fclean all
.PHONY: all clean fclean re














