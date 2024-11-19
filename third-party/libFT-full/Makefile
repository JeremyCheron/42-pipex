# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 15:12:51 by jcheron           #+#    #+#              #
#    Updated: 2024/11/18 12:13:16 by jcheron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM					=		/usr/bin/rm -f
ECHO				=		/usr/bin/echo

# ############################################################################ #
#                                                                              #
#                           Variables                                          #
#                                                                              #
# ############################################################################ #

SRC_DIR				:=		src
INC_DIR				:=		include
OBJ_DIR				:=		obj
TARGET				:=		libftfull.a
CC					:=		cc
CCFLAGS				:=		-Wall -Werror -Wextra
# include	srcs.mk

FILES = $(shell find $(SRC_DIR) -type f -name "*.c" | sed 's/\.c//' | sed 's/$(SRC_DIR)//')
# ############################################################################ #
#                                                                              #
#                           Objects                                            #
#                                                                              #
# ############################################################################ #

OBJS				:=		$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))

# ############################################################################ #
#                                                                              #
#                           Colors                                             #
#                                                                              #
# ############################################################################ #

DEF_COLOR			=	\033[0;39m
GRAY				=	\033[0;90m
RED					=	\033[0;91m
GREEN				=	\033[0;92m
YELLOW				=	\033[0;93m
BLUE				=	\033[0;94m
MAGENTA				=	\033[0;95m
CYAN				=	\033[0;96m
WHITE				=	\033[0;97m
TERM_UP				=	\033[1A
TERM_CLEAR_LINE		=	\033[2K\r

# ############################################################################ #
#                                                                              #
#                           Bin / Lib                                          #
#                                                                              #
# ############################################################################ #

$(TARGET): _header _obj_header $(OBJS) _obj_footer
	@printf "$(MAGENTA)Making archive $(BLUE)\"%s\"$(MAGENTA)...$(DEF_COLOR)" $@
	@ar -rcs $@ $(OBJS)
	@printf "$(TERM_CLEAR_LINE)$(GREEN)Done building archive $(BLUE)\"%s\"$(GREEN) !\n$(DEF_COLOR)" $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "$(TERM_CLEAR_LINE)$(MAGENTA)Compiling $(BLUE)\"%s\"$(MAGENTA)...\n$(DEF_COLOR)" $@
	@mkdir -p $(@D)
	@$(CC) -c $< -o $@ -I$(INC_DIR) $(CFLAGS)
	@printf "$(TERM_UP)"

# ############################################################################ #
#                                                                              #
#                           Rules                                              #
#                                                                              #
# ############################################################################ #

.PHONY:	all clean fclean re norminette _header _obj_header _obj_footer test

all:	$(TARGET)

clean:
		@printf "$(YELLOW)Removing %d objects...\n$(DEF_COLOR)" $(words $(OBJS))
		@$(RM) -rf $(OBJ_DIR)

fclean: clean
		@printf "$(YELLOW)Removing \"%s\"...\n$(DEF_COLOR)" $(TARGET)
		@$(RM) $(TARGET)

re:		fclean all

norminette:
		@norminette $(SRC_DIR) $(INC_DIR) | grep -Ev '^Notice|OK!$$'	\
		&& $(ECHO) -e '\033[1;31mNorminette KO!'						\
		|| $(ECHO) -e '\033[1;32mNorminette OK!'

_header:
		@printf "$(GREEN)Welcome to $(BLUE)\"%s\"$(GREEN) builder !\n$(DEF_COLOR)" $(TARGET)

_obj_header:
		@printf "$(MAGENTA)Building objects$(DEF_COLOR)...\n"

_obj_footer:
		@printf "$(TERM_UP)$(TERM_CLEAR_LINE)$(GREEN)Done building $(BLUE)%d$(GREEN) object(s) !\n$(DEF_COLOR)" $(words $(OBJS))


include test.mk
