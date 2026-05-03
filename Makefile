#-----------------------COMPILATION------------------------------------------------------
# Compiler and Flags
CC						:= cc
CFLAGS				 	 = -Wall -Wextra -Werror $(INCLUDES)
LDFLAGS					:= -lreadline
INCLUDES				 = $(addprefix -I,$(SRC_DIRS)) $(addprefix -I,$(LIB_DIRS))

#-----------------------BINARIES---------------------------------------------------------
# Output Files
NAME					:= minishell
EXECUTOR				:= libminishell.a

#-----------------------FOLDERS----------------------------------------------------------
# Directories
SRC_DIR					:= src
BUILD_DIR				:= build
OBJ_DIR					:= $(BUILD_DIR)/obj
TESTS_DIR				:= tests
TESTS_BIN_FOLDER		:= $(BUILD_DIR)/tests

SRC_DIRS				 = $(patsubst %/, %, $(sort $(dir $(HEADERS))))
							
# Library directories (libraries/)
LIB_DIR					:= libraries
LIST_LIB_DIR			:= $(LIB_DIR)/list
STRING_ARRAY_LIB_DIR	:= $(LIB_DIR)/string_array
STRING_LIB_DIR			:= $(LIB_DIR)/ft_string
CONVERTER_LIB_DIR		:= $(LIB_DIR)/converter
FT_MEMORY_LIB_DIR		:= $(LIB_DIR)/ft_memory

# List of all library directories
LIB_DIRS				:= $(LIST_LIB_DIR) \
							$(STRING_ARRAY_LIB_DIR) \
							$(STRING_LIB_DIR) \
							$(CONVERTER_LIB_DIR) \
							$(FT_MEMORY_LIB_DIR)

#-----------------------FILES------------------------------------------------------------
# Sources
C_FILES 				:= $(shell find $(SRC_DIR) -name '*.c')
HEADERS 				:= $(shell find $(SRC_DIR) -name '*.h')

# Objects
OBJ     				:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(C_FILES))

#-----------------------LIBRARIES--------------------------------------------------------
# Library files
LIST_LIB				:= $(LIST_LIB_DIR)/list.a
STRING_ARRAY_LIB		:= $(STRING_ARRAY_LIB_DIR)/string_array.a
CONVERTER_LIB			:= $(CONVERTER_LIB_DIR)/converter.a
FT_MEMORY_LIB			:= $(FT_MEMORY_LIB_DIR)/ft_memory.a

# Libraries
LIBRARIES				:= $(LIST_LIB) \
							$(STRING_ARRAY_LIB) \
							$(CONVERTER_LIB) \
							$(FT_MEMORY_LIB)

#-----------------------COLORS-----------------------------------------------------------
# Colors for Output
GREEN					:= \033[0;32m
RED						:= \033[31m
BLUE					:= \033[0;34m
YELLOW					:= \033[0;33m
RESET					:= \033[0m

#-----------------------RULES------------------------------------------------------------
# Default Target
all: $(NAME)

# Build the Executable
$(NAME): $(OBJ) $(LIBRARIES)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

# Compile Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) Makefile
	$(if $(COMPILE_MSG_SHOWN),,$(eval COMPILE_MSG_SHOWN := 1) \
	@echo "$(YELLOW)>> Compiling object files:$(RESET)")
	@printf "$(YELLOW)   %-38.38s\r" $(notdir $@)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile libraries
%.a:
	@cd $(dir $@); $(MAKE) > /dev/null; $(MAKE) clean > /dev/null

# Clean up Object Files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Removed object files$(RESET)"
	@for lib in $(LIB_DIR)/*; do \
		$(MAKE) -C $$lib clean > /dev/null; \
	done

# Clean up All Generated Files
fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Removed $(NAME)$(RESET)"
	@for lib in $(LIB_DIR)/*; do \
		$(MAKE) -C $$lib fclean > /dev/null; \
	done

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re
