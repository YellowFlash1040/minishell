# Compiler and Flags
CC				:= cc
CFLAGS			 = -Wall -Wextra -Werror $(INCLUDES) -g

# Output Files
NAME			:= string_array.a

# Directories
SRC_DIR			:= .
OBJ_DIR			:= obj
LIB_DIR			:= ..

#Libraries folders
STRING_LIB_DIR	:= $(LIB_DIR)/ft_string

# Includes
INCLUDES		:= -I$(SRC_DIR) -I$(STRING_LIB_DIR)

# Files
FILES			:= string_array.c

# Headers
HEADERS			:= string_array.h

# Sources, Objects
SRC				:= $(addprefix $(SRC_DIR)/, $(FILES:.c=.o))
OBJ     		:= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

#Libraries
STRING_LIB		:= $(STRING_LIB_DIR)/ft_string.a

#All Libraries in one variable
LIBS			:= $(STRING_LIB)

# Colors for Output
GREEN			:= \033[0;32m
RED				:= \033[31m
RESET			:= \033[0m

# Default Target
all: $(NAME)

# Build the Executable
$(NAME): $(OBJ) $(LIBS)
	@cp $(STRING_LIB) $@
	@ar src $@ $<
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

#Compile Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile libraries
%.a:
	@cd $(dir $@); $(MAKE) > /dev/null; $(MAKE) clean > /dev/null

# Clean up Object Files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Removed object files$(RESET)"
	@for lib in $(dir $(LIBS)); do \
		$(MAKE) -C $$lib clean > /dev/null; \
	done

# Clean up All Generated Files
fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Removed $(NAME)$(RESET)"
	@for lib in $(dir $(LIBS)); do \
		$(MAKE) -C $$lib fclean > /dev/null; \
	done

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re
