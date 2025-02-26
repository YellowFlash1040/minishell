# Compiler and Flags
CC				:= cc
CFLAGS			 = -Wall -Wextra -Werror $(INCLUDES) -g

# Output Files
NAME			:= minishell

# Directories
SRC_DIR			:= src
OBJ_DIR			:= obj
LIB_DIR 		:= libraries

# Source directories
BUILDERS_DIR	:= $(SRC_DIR)/builders
HELPERS_DIR		:= $(SRC_DIR)/helpers
LOGIC_DIR		:= $(SRC_DIR)/logic
MODEL_DIR		:= $(SRC_DIR)/model
SHARED_DIR		:= $(SRC_DIR)/shared

# List of all source directories
SRC_DIRS		:= $(SRC_DIR) \
					$(BUILDERS_DIR) \
					$(HELPERS_DIR) \
					$(LOGIC_DIR) \
					$(MODEL_DIR) \
					$(SHARED_DIR)

# Libraries directories
LIST_LIB_DIR	:= $(LIB_DIR)/list

# Includes
INCLUDES		:= -I$(SRC_DIR) \
					-I$(BUILDERS_DIR) \
					-I$(HELPERS_DIR) \
					-I$(LOGIC_DIR) \
					-I$(MODEL_DIR) \
					-I$(SHARED_DIR) \
					-I$(LIST_LIB_DIR)

# Sources
C_FILES			:= $(notdir $(wildcard $(SRC_DIR)/*.c)) \
					$(notdir $(wildcard $(BUILDERS_DIR)/*.c)) \
					$(notdir $(wildcard $(HELPERS_DIR)/*.c)) \
					$(notdir $(wildcard $(LOGIC_DIR)/*.c)) \
					$(notdir $(wildcard $(MODEL_DIR)/*.c)) \
					$(notdir $(wildcard $(SHARED_DIR)/*.c))
HEADERS			:= $(notdir $(wildcard $(BUILDERS_DIR)/*.h)) \
					$(notdir $(wildcard $(HELPERS_DIR)/*.h)) \
					$(notdir $(wildcard $(LOGIC_DIR)/*.h)) \
					$(notdir $(wildcard $(MODEL_DIR)/*.h)) \
					$(notdir $(wildcard $(SHARED_DIR)/*.h))

# Objects
OBJ     		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_FILES)) \
					$(patsubst $(BUILDERS_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_FILES)) \
					$(patsubst $(HELPERS_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_FILES)) \
					$(patsubst $(LOGIC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_FILES)) \
					$(patsubst $(MODEL_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_FILES)) \
					$(patsubst $(SHARED_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_FILES)) \

# Library files
LIST_LIB		:= $(LIST_LIB_DIR)/list.a

# Libraries
LIBRARIES		:= $(LIST_LIB)

# Colors for Output
GREEN			:= \033[0;32m
RED				:= \033[31m
RESET			:= \033[0m

vpath %.c $(SRC_DIRS)

# Default Target
all: $(NAME)

# Build the Executable
$(NAME): $(OBJ) $(LIBRARIES)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

# Compile Object Files
$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile libraries
%.a:
	@cd $(dir $@); $(MAKE) > /dev/null; $(MAKE) clean > /dev/null
	@# echo "$(GREEN)Compiled $(notdir $@) successfully!$(RESET)"

# Clean up Object Files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Removed object files$(RESET)"
	@for lib in $(LIB_DIR)/*/; do \
		$(MAKE) -C $$lib clean > /dev/null; \
	done
	@# echo "$(RED)Removed libraries object files$(RESET)"

# Clean up All Generated Files
fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Removed $(NAME)$(RESET)"
	@for lib in $(LIB_DIR)/*/; do \
		$(MAKE) -C $$lib fclean > /dev/null; \
	done
	@# echo "$(RED)Removed .a libraries$(RESET)"

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re