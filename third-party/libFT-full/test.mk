# ############################################################################ #
#                                                                              #
#                           Tests / Test Rules                                 #
#                                                                              #
# ############################################################################ #

REPO_URL			:=		git@github.com:JeremyCheron/42TestRepo.git
TEST_DIR			:=		tests/
TEST_LIBFT			:=		$(TEST_DIR)libft_test.c
TEST_OBJS_LIBFT		:=		$(TEST_DIR)libft_test.o
TEST_PRINTF			:=		$(TEST_DIR)printf_test.c
TEST_OBJS_PRINTF	:=		$(TEST_DIR)printf_test.o
TEST_VPRINTF		:=		$(TEST_DIR)vprintf_test.c
TEST_OBJS_VPRINTF	:=		$(TEST_DIR)vprintf_test.o
TEST_GNL			:=		$(TEST_DIR)gnl_test.c
TEST_OBJS_GNL		:=		$(TEST_DIR)gnl_test.o

clone:
		@if [ ! -d "$(TEST_DIR)" ]; then \
			echo "Cloning repository..."; \
			git clone $(REPO_URL) $(TEST_DIR); \
		else \
			echo "Directory '$(TEST_DIR)' already exists. Skipping clone then pull."; \
			cd $(TEST_DIR) && git pull; \
		fi

$(TEST_DIR)%.o: $(TEST_DIR)%.c
	@printf "$(TERM_CLEAR_LINE)$(MAGENTA)Compiling test $(BLUE)\"%s\"$(MAGENTA)...\n$(DEF_COLOR)" $@
	@$(CC) -c $< -o $@ -I$(INC_DIR) $(CCFLAGS)
	@printf "$(TERM_UP)"

testlibft: $(TARGET) $(TEST_OBJS_LIBFT)
	@echo -e "$(MAGENTA)Running tests...$(DEF_COLOR)"
	@$(CC) $(CCFLAGS) -I$(INC_DIR) -o $(TEST_DIR)tester $(TEST_OBJS_LIBFT) $(TARGET) -lbsd
	@./$(TEST_DIR)tester

testprintf: $(TARGET) $(TEST_OBJS_PRINTF)
	@echo -e "$(MAGENTA)Running tests...$(DEF_COLOR)"
	@$(CC) $(CCFLAGS) -I$(INC_DIR) -o $(TEST_DIR)tester $(TEST_OBJS_PRINTF) $(TARGET)
	@./$(TEST_DIR)tester

testvprintf: $(TARGET) $(TEST_OBJS_VPRINTF)
	@echo -e "$(MAGENTA)Running tests...$(DEF_COLOR)"
	@$(CC) $(CCFLAGS) -I$(INC_DIR) -o $(TEST_DIR)tester $(TEST_OBJS_VPRINTF) $(TARGET)
	@./$(TEST_DIR)tester

testgnl: $(TARGET) $(TEST_OBJS_GNL)
	@echo -e "$(MAGENTA)Running tests...$(DEF_COLOR)"
	@$(CC) $(CCFLAGS) -I$(INC_DIR) -o $(TEST_DIR)tester $(TEST_OBJS_GNL) $(TARGET)
	@./$(TEST_DIR)tester
