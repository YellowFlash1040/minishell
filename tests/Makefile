#-----------------------COMPILATION------------------------------------------------------
# Compiler and Flags
CC				:= cc
CFLAGS			 = -Wall -Wextra -Werror $(INCLUDES) -g
LDFLAGS			:= -L.. -lminishell
INCLUDES		 = -I$(HELPERS_DIR) \
					$(addprefix -I, $(shell find ../src -type d)) \
					$(addprefix -I, $(shell find ../libraries -type d))

#-----------------------BINARIES---------------------------------------------------------
# Output Files
TEST_BINS		 = $(addprefix $(BIN_DIR)/,$(notdir $(TEST_FILES:.c=)))
# TEST_BINS		 = $(BIN_DIR)/run_a_pipeline.test
# TEST_BINS		 = $(BIN_DIR)/run_a_command.test
# TEST_BINS		 = $(BIN_DIR)/echo.test
# TEST_BINS		 = $(BIN_DIR)/export.test
# TEST_BINS		 = $(BIN_DIR)/cd.test $(BIN_DIR)/run_a_pipeline.test
# TEST_BINS		 = $(BIN_DIR)/cd.test
# TEST_BINS		 = $(BIN_DIR)/pwd.test
# TEST_BINS		 = $(BIN_DIR)/exit.test
# TEST_BINS		 = $(BIN_DIR)/run_a_pipeline_2.test
# TEST_BINS		 = $(BIN_DIR)/none_existing_file.test
MINISHELL		 = $(MINISHELL_DIR)/libminishell.a

#-----------------------FOLDERS----------------------------------------------------------
# Directories
SRC_DIR			:= src
OBJ_DIR			:= obj
BIN_DIR			:= bin
MINISHELL_DIR	:= ..

# Source subdirectories
HELPERS_DIR		:= $(SRC_DIR)/helpers
TESTS_DIR		:= $(SRC_DIR)/tests
EXECUTOR_DIR	:= $(TESTS_DIR)/executor
BUILTINS_DIR	:= $(TESTS_DIR)/builtins

TESTS_DIRS		:= $(EXECUTOR_DIR) \
					$(BUILTINS_DIR)

# All source folders
SRC_DIRS		:= $(TESTS_DIRS) \
					$(HELPERS_DIR)

#-----------------------FILES------------------------------------------------------------
# Sources
C_FILES			:= $(wildcard $(HELPERS_DIR)/*.c)
TEST_FILES		:= $(foreach dir,$(TESTS_DIRS),$(wildcard $(dir)/*.c))

# Objects
OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(C_FILES)))

#-----------------------COLORS-----------------------------------------------------------
# Colors for Output
GREEN			:= \033[0;32m
RED				:= \033[31m
BOLD_BLUE		:= \033[1;34m
RESET			:= \033[0m

#-----------------------RULES------------------------------------------------------------
vpath %.c $(SRC_DIRS)

# Default Target
all: $(TEST_BINS)

# Build the Tests
$(BIN_DIR)/%.test: %.test.c $(OBJ) $(MINISHELL)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $< $(OBJ) $(LDFLAGS) -o $@
	@#echo "$(GREEN)Compiled $(notdir $@) successfully!$(RESET)"

# Compile Object Files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(MINISHELL):
	@make $(notdir $(MINISHELL)) -C $(MINISHELL_DIR) > /dev/null

# Clean up Object Files
clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MINISHELL)
	@make -C $(MINISHELL_DIR) clean > /dev/null

# Clean up All Generated Files
fclean: clean
	@rm -rf $(BIN_DIR)
	@make -C $(MINISHELL_DIR) fclean > /dev/null

# Rebuild the Project
re: fclean all

# Run the Tests
run: $(TEST_BINS)
	@for test in $(notdir $(TEST_BINS)); do \
		echo "$(BOLD_BLUE)Running $$test$(RESET)"; \
		$(BIN_DIR)/$$test; \
		echo ""; \
	done

print:
	@echo "CC: $(CC)"
	@echo "CFLAGS: $(CFLAGS)"
	@echo "LDFLAGS: $(LDFLAGS)"
	@echo "TEST_BINS: $(TEST_BINS)"
	@echo "MINISHELL: $(MINISHELL)"
	@echo "SRC_DIR: $(SRC_DIR)"
	@echo "OBJ_DIR: $(OBJ_DIR)"
	@echo "BIN_DIR: $(BIN_DIR)"
	@echo "MINISHELL_DIR: $(MINISHELL_DIR)"
	@echo "HELPERS_DIR: $(HELPERS_DIR)"
	@echo "TESTS_DIR: $(TESTS_DIR)"
	@echo "INCLUDES: $(INCLUDES)"
	@echo "C_FILES: $(C_FILES)"
	@echo "TEST_FILES: $(TEST_FILES)"
	@echo "OBJ: $(OBJ)"
	@echo "GREEN: $(GREEN)"
	@echo "RED: $(RED)"
	@echo "BOLD_BLUE: $(BOLD_BLUE)"
	@echo "RESET: $(RESET)"

# Phony Targets
.PHONY: all clean fclean re run $(MINISHELL)
