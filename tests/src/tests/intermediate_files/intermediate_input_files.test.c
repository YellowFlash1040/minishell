#include "command_runner.h"
#include "helpers.h"

t_list* environment;

int	test1(void);
int	test2(void);
int	test3(void);
int	test4(void);
int test5(void);

int main(int argc, t_string args[], t_string envp[])
{
	(void)argc;
	(void)args;

	environment = init_environment(envp);

	int (*tests[])(void) =
		{
			test1,
			test2,
			test3,
			test4,
			test5
		};

	for (int i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++)
		run_a_test(tests[i], i + 1, false);

	destroy_environment(&environment);
}

int test1(void)
{
	int			result;
	t_command	*command;

	/*
		grep r < input_file_1.txt < input_file_2.txt
	*/

	char *exe_path = "grep";
	char *args[] = {exe_path, "r", NULL};
	command = create_command(exe_path, args, "assets/intermediate_files/input_files/test1/input_file_2.txt", NULL);
	command->needs_a_subshell = false;
	command->environment = environment;

	t_file* file = init_file();
	file->path = ft_strdup("assets/intermediate_files/input_files/test1/input_file_1.txt");
	file->mode = READ;
	add_to_list(command->intermediate_files, file);

	result = run_a_command(command);
	
	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test2(void)
{
	int			result;
	t_command	*command;

	/*
		grep r < input_file_1.txt < input_file_2.txt
	*/

	char *exe_path = "grep";
	char *args[] = {exe_path, "r", NULL};
	command = create_command(exe_path, args, "assets/intermediate_files/input_files/test2/input_file_2.txt", NULL);
	command->needs_a_subshell = false;
	command->environment = environment;

	t_file* file = init_file();
	file->path = ft_strdup("assets/intermediate_files/input_files/test2/input_file_1.txt");
	file->mode = READ;
	add_to_list(command->intermediate_files, file);

	result = run_a_command(command);
	
	if (command->exit_status_code != FAILURE)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test3(void)
{
	int			result;
	t_command	*command;

	/*
		grep r < input_file_1.txt < input_file_2.txt < input_file_3.txt
	*/

	t_string asset_files_path = "assets/intermediate_files/input_files/test3/";
	t_string input_file_path = ft_strjoin(asset_files_path, "input_file_3.txt");

	char *exe_path = "grep";
	char *args[] = {exe_path, "r", NULL};
	command = create_command(exe_path, args, input_file_path, NULL);
	free(input_file_path);
	command->needs_a_subshell = false;
	command->environment = environment;

	t_file* file = init_file();
	file->path = ft_strjoin(asset_files_path, "input_file_1.txt");
	file->mode = READ;
	add_to_list(command->intermediate_files, file);
	file = init_file();
	file->path = ft_strjoin(asset_files_path, "input_file_2.txt");
	file->mode = READ;
	add_to_list(command->intermediate_files, file);

	result = run_a_command(command);
	
	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test4(void)
{
	int			result;
	t_command	*command;

	/*
		grep r < input_file_1.txt < input_file_2.txt < input_file_3.txt
	*/

	t_string asset_files_path = "assets/intermediate_files/input_files/test4/";
	t_string input_file_path = ft_strjoin(asset_files_path, "input_file_3.txt");

	char *exe_path = "grep";
	char *args[] = {exe_path, "r", NULL};
	command = create_command(exe_path, args, input_file_path, NULL);
	free(input_file_path);
	command->needs_a_subshell = false;
	command->environment = environment;

	t_file* file = init_file();
	file->path = ft_strjoin(asset_files_path, "input_file_1.txt");
	file->mode = READ;
	add_to_list(command->intermediate_files, file);
	file = init_file();
	file->path = ft_strjoin(asset_files_path, "input_file_2.txt");
	file->mode = READ;
	add_to_list(command->intermediate_files, file);

	result = run_a_command(command);
	
	if (command->exit_status_code != FAILURE)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test5(void)
{
	int			result;
	t_command	*command;

	/*
		grep r < input_file_1.txt < input_file_2.txt
	*/

	t_string asset_files_path = "assets/intermediate_files/input_files/test5/";
	t_string input_file_path = ft_strjoin(asset_files_path, "input_file_2.txt");

	char *exe_path = "grep";
	char *args[] = {exe_path, "r", NULL};
	command = create_command(exe_path, args, input_file_path, NULL);
	free(input_file_path);
	command->needs_a_subshell = false;
	command->environment = environment;

	t_file* file = init_file();
	file->path = ft_strjoin(asset_files_path, "input_file_1.txt");
	file->mode = READ;
	add_to_list(command->intermediate_files, file);

	result = run_a_command(command);
	
	if (command->exit_status_code != FAILURE)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}
