# Compiler and Flags
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g

# Output Files
NAME		:= ft_string.a

# Directories
OBJ_DIR		:= obj

# Files
FILES		:= ft_string.c \
				ft_string_2.c \
				ft_string_3.c \
				ft_string_class.c

#Headers
HEADERS		:= ft_string.h

# Sources, Objects
OBJ     	:= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

# Colors for Output
GREEN		:= \033[0;32m
RED			:= \033[31m
RESET		:= \033[0m

# Default Target
all: $(NAME)

# Build the Executable
$(NAME): $(OBJ)
	@ar src $@ $(OBJ)
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

#Compile Object Files
$(OBJ_DIR)/%.o: %.c $(HEADERS)
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