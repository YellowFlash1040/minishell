# Compiler, Flags and Tools
CC				:= cc
CFLAGS			 = -Wextra -Werror -Wall $(INCLUDES)
RM				:= rm -rf
MAKE			:= make -s

# Output Files
NAME			:= ft_printf.a

# Directories
OBJ_DIR			:= obj
LIB_STRING_DIR 	:= ../ft_string

# Sources and Objects
SRC				:= ft_print_char_bonus.c \
					ft_printf.c \
					ft_printf_set_options.c \
					ft_printf_utils.c \
					ft_print_hex_bonus.c \
					ft_print_number_bonus.c \
					ft_print_number_left_aligned_bonus.c \
					ft_print_number_right_aligned_bonus.c \
					ft_print_numbers.c \
					ft_print_pointer_bonus.c \
					ft_print_string_and_pointer.c \
					ft_print_string_bonus.c \
					ft_print_unsigned_bonus.c
OBJ				:=  $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Includes
INCLUDES		:= -I$(LIB_STRING_DIR) \

# External Libraries
LIB_STRING		:= $(LIB_STRING_DIR)/ft_string.a

# Colors for Output
GREEN			:= \033[0;32m
RED				:= \033[31m
RESET			:= \033[0m

# Default Target
all: $(NAME)

# Bonus Target
bonus: $(NAME)

# Build the Executable
$(NAME): $(OBJ) $(LIB_STRING)
	@cp $(LIB_STRING) $(NAME);
	@ar src $@ $(OBJ)
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

#Compile Object Files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

%.a:
	@cd $(dir $@); $(MAKE); $(MAKE) clean > /dev/null

# Clean up Object Files
clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)Removed object files$(RESET)"

# Clean up All Generated Files
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Removed $(NAME)$(RESET)"

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re bonus