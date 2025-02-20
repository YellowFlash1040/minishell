# Compiler and Flags
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g

# Output Files
NAME		:= list.a

# Directories
SRC_DIR		:= .
OBJ_DIR		:= obj

# Includes
INCLUDES	:= -I$(SRC_DIR)

# Files
FILES		:= list.c \
				list_2.c

# Sources, Objects
SRC			:= $(addprefix $(SRC_DIR)/, $(FILES:.c=.o))
OBJ     	:= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

# Colors for Output
GREEN		:= \033[0;32m
RED			:= \033[31m
RESET		:= \033[0m

# Default Target
all: $(NAME)

# Build the Executable
$(NAME): $(OBJ)
	@ar src $@ $^
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

#Compile Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up Object Files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Removed object files$(RESET)"

# Clean up All Generated Files
fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Removed $(NAME)$(RESET)"

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re