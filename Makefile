#-----------------------COMPILATION------------------------------------------------------
# Compiler and Flags
CC						:= cc
CFLAGS				 	 = -Wall -Wextra -Werror $(INCLUDES) -g
LDFLAGS					:= -lreadline
INCLUDES				 = $(addprefix -I,$(SRC_DIRS)) $(addprefix -I,$(LIB_DIRS))

#-----------------------BINARIES---------------------------------------------------------
# Output Files
NAME					:= minishell
EXECUTOR				:= libminishell.a

#-----------------------FOLDERS----------------------------------------------------------
# Directories
SRC_DIR					:= src
OBJ_DIR					:= obj
LIB_DIR 				:= libraries

# Source directories (src/)
BUILDERS_DIR			:= $(SRC_DIR)/builders
HELPERS_DIR				:= $(SRC_DIR)/helpers
LOGIC_DIR				:= $(SRC_DIR)/logic
MODEL_DIR				:= $(SRC_DIR)/model
SHARED_DIR				:= $(SRC_DIR)/shared

# Logic directories (src/logic/)
EXECUTOR_DIR			:= $(LOGIC_DIR)/executor
BUILTINS_DIR			:= $(LOGIC_DIR)/builtins
ENVIRONMENT_DIR			:= $(LOGIC_DIR)/environment
PARSER_DIR				:= $(LOGIC_DIR)/parser
SIGNALS_DIR				:= $(LOGIC_DIR)/signals
EXPANDER_DIR			:= $(LOGIC_DIR)/expander

# Executor directories (src/logic/executor/)
COMMAND_RUNNER_DIR		:= $(EXECUTOR_DIR)/command_runner
PIPELINE_RUNNER_DIR		:= $(EXECUTOR_DIR)/pipeline_runner
FDS_DIR					:= $(COMMAND_RUNNER_DIR)/fds

# Builtin directories (src/logic/builtins/)
CD_DIR					:= $(BUILTINS_DIR)/cd
ECHO_DIR				:= $(BUILTINS_DIR)/echo
EXPORT_DIR				:= $(BUILTINS_DIR)/export
SET_DIR					:= $(BUILTINS_DIR)/set
UNSET_DIR				:= $(BUILTINS_DIR)/unset
ENV_DIR					:= $(BUILTINS_DIR)/env
PWD_DIR					:= $(BUILTINS_DIR)/pwd
EXIT_DIR				:= $(BUILTINS_DIR)/exit_builtin

# Logic directories (src/model/)
ENVIRONMENT_MODEL_DIR	:= $(MODEL_DIR)/environment
GENERAL_MODEL_DIR		:= $(MODEL_DIR)/general
IO_MODEL_DIR			:= $(MODEL_DIR)/io

# List of all source directories
SRC_DIRS				:= $(SRC_DIR) \
							$(BUILDERS_DIR) \
							$(HELPERS_DIR) \
							$(LOGIC_DIR) \
							$(MODEL_DIR) \
							$(SHARED_DIR) \
							$(EXECUTOR_DIR) \
							$(BUILTINS_DIR) \
							$(COMMAND_RUNNER_DIR) \
							$(FDS_DIR) \
							$(PIPELINE_RUNNER_DIR) \
							$(EXPANDER_DIR) \
							$(CD_DIR) \
							$(ECHO_DIR) \
							$(EXPORT_DIR) \
							$(SET_DIR) \
							$(UNSET_DIR) \
							$(ENV_DIR) \
							$(PWD_DIR) \
							$(EXIT_DIR) \
							$(ENVIRONMENT_DIR) \
							$(VARIABLES_EXPANDER_DIR) \
							$(PARSER_DIR) \
							$(ENVIRONMENT_MODEL_DIR) \
							$(GENERAL_MODEL_DIR) \
							$(IO_MODEL_DIR) \
							$(SIGNALS_DIR) \
							$(EXPANDER_DIR)

# Library directories (libraries/)
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
C_FILES 				:= $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
HEADERS 				:= $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.h))

# Objects
OBJ     				:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(C_FILES)))

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
RESET					:= \033[0m

#-----------------------RULES------------------------------------------------------------
vpath %.c $(SRC_DIRS)

# Default Target
all: $(NAME)

# Build the Executable
$(NAME): $(OBJ) $(LIBRARIES)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

# Compile Object Files
$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile libraries
%.a:
	@cd $(dir $@); $(MAKE) > /dev/null; $(MAKE) clean > /dev/null

$(EXECUTOR): $(OBJ) $(LIBRARIES)
	@for lib in $(LIBRARIES); do \
		ar x $$lib ; \
		ar src $@ *.o ; \
		rm *.o ; \
	done
	@ar src $@ $(OBJ)
	@ar d $@ main.o

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

leaks: fclean compile_leaks

compile_leaks: $(OBJ) $(LIBRARIES)
	@$(CC) $(CFLAGS) -fsanitize=leak $^ $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re
