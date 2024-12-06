# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 08:20:00 by jcheron           #+#    #+#              #
#    Updated: 2024/12/06 09:46:58 by jcheron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
NAME			=	pipex
THIRD_PARTY_DIR	=	third-party
SRC_DIR			=	sources
INC_DIR			=	includes
OBJS_DIR		=	objs

LIB_FT_PATH		=	$(THIRD_PARTY_DIR)/libFT-full
LIB_FT_INC		=	$(LIB_FT_PATH)/libftfull.a

CFLAGS			=									\
					-Wall -Wextra -Werror -g		\
					-I$(INC_DIR)					\
					# $(LIB_FT_PATH)$(LIB_FT_INC)		\
					# $(LIB_MLX)

LFLAGS			=									\
					-L$(LIB_FT_PATH)				\
					-lftfull						\

FILES			=	checkers errs read_cmd pipex

SRCS			=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))

OBJS			=	$(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

.PHONY: all clean fclean re cleanlibs fcleanlibs libft

all: $(NAME)

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

cleanlibs:
	$(MAKE) clean -C $(LIB_FT_PATH)

fcleanlibs:
	$(MAKE) fclean -C $(LIB_FT_PATH)

libft:
	make -C $(LIB_FT_PATH)


$(NAME): libft $(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LFLAGS)


$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@ -I$(INC_DIR) $(CFLAGS)

