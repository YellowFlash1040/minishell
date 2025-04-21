#-----------------------COMPILATION------------------------------------------------------
# Compiler and Flags
CC						:= cc
CFLAGS				 	 = -Wall -Wextra -Werror $(INCLUDES) -g
INCLUDES				 = $(addprefix -I,$(SRC_DIRS)) $(addprefix -I,$(LIB_DIRS))

#-----------------------BINARIES---------------------------------------------------------
# Output Files
NAME					:= ft_memory.a

#-----------------------FOLDERS----------------------------------------------------------
# Directories
SRC_DIR					:= .
OBJ_DIR					:= obj

# List of all source directories
SRC_DIRS				:= $(SRC_DIR)

#-----------------------FILES------------------------------------------------------------
# Sources
C_FILES 				:= ft_bzero.c \
							ft_calloc.c \
							ft_memchr.c \
							ft_memcmp.c \
							ft_memcpy.c \
							ft_memmove.c \
							ft_memset.c
HEADERS 				:= ft_memory.h

# Objects
OBJ     				:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(C_FILES)))

#-----------------------COLORS-----------------------------------------------------------
# Colors for Output
GREEN					:= \033[0;32m
RED						:= \033[31m
RESET					:= \033[0m

#-----------------------RULES------------------------------------------------------------
vpath %.c $(SRC_DIRS)

# Default Target
all: $(NAME)

# Build the library
$(NAME): $(OBJ)
	@ar src $@ $^
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

# Compile Object Files
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
