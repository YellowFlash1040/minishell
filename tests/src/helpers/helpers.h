#ifndef HELPERS_H
# define HELPERS_H

# include "command_builder.h"
# include "pipeline_builder.h"
# include <stdlib.h>
# include <stdio.h>

void		run_a_test(int (*test)(void), int index);
t_command	*create_command(char *exe_path, char **args, char *input_file, char *output_file);
void		setup_command(t_command *command, char *exe_path, char **args, char *input_file, char *output_file);

#endif