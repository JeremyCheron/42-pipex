SRCS		=	ft_putchar.c \ ft_iswhitespace.c ft_putndl.c ft_putstr.c \
				ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
				ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
				ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
				ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_striteri.c \
				ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
				ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
				ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c \
OBJS		= $(SRCS:.c=.o)

BONUS		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS	= $(BONUS:.c=.o)

TEST		= $(TEST_DIR)test.c

TEST_OBJS	= $(TEST:.c=.o)

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

NAME		= libft.a
LIBFT		= libft
TEST_DIR	= tests/

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS) $(TEST_DIR)test.o

fclean:		clean
				$(RM) $(NAME)

re:			fclean $(NAME)

bonus:		$(OBJS) $(BONUS_OBJS)
			@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

test:		$(NAME) $(BONUS_OBJS) $(TEST_OBJS)
			@echo -e "$(MAGENTA)Running tests...$(DEF_COLOR)"
			@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS) $(TEST_OBJS)
			@$(CC) $(CFLAGS) -o $(TEST_DIR)test $(TEST_OBJS) $(NAME)
			@./$(TEST_DIR)test

.PHONY:		all clean fclean re bonus
