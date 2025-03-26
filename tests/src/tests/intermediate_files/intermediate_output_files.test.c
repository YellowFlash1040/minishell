#include "command_runner.h"
#include "helpers.h"

t_list* environment;

int	test1(void);
int	test2(void);
int	test3(void);
int	test4(void);

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
		test4
	};

	for (int i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++)
		run_a_test(tests[i], i + 1, false);

	// test1();

	destroy_environment(&environment);
}

int test1(void)
{
	int			result;
	t_command	*command;

	/*
		grep r > output_file_1.txt > output_file_2.txt
	*/

	t_string asset_files_path = "assets/intermediate_files/output_files/test1/";
	t_string output_file_path = ft_strjoin(asset_files_path, "output_file_2.txt");

	char *exe_path = "grep";
	char *args[] = {exe_path, "r", NULL};
	command = create_command(exe_path, args, NULL, output_file_path);
	free(output_file_path);
	command->environment = environment;

	t_file* file = init_file();
	file->path = ft_strjoin(asset_files_path, "output_file_1.txt");
	file->mode = TRUNCATE;
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
		grep r > output_file_1.txt > output_file_2.txt
	*/

	t_string asset_files_path = "assets/intermediate_files/output_files/test2/";
	t_string output_file_path = ft_strjoin(asset_files_path, "output_file_2.txt");

	char *exe_path = "grep";
	char *args[] = {exe_path, "r", NULL};
	command = create_command(exe_path, args, NULL, output_file_path);
	free(output_file_path);
	command->environment = environment;

	t_file* file = init_file();
	file->path = ft_strjoin(asset_files_path, "output_file_1.txt");
	file->mode = TRUNCATE;
	add_to_list(command->intermediate_files, file);
	file = init_file();

	result = run_a_command(command);
	
	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test3(void)
{
	int			result;
	t_command	*command;

	/*
		grep r > output_file_1.txt > output_file_2.txt > output_file_3.txt
	*/

	t_string asset_files_path = "assets/intermediate_files/output_files/test3/";
	t_string output_file_path = ft_strjoin(asset_files_path, "output_file_3.txt");

	char *exe_path = "grep";
	char *args[] = {exe_path, "r", NULL};
	command = create_command(exe_path, args, NULL, output_file_path);
	free(output_file_path);
	command->environment = environment;

	t_file* file = init_file();
	file->path = ft_strjoin(asset_files_path, "output_file_1.txt");
	file->mode = TRUNCATE;
	add_to_list(command->intermediate_files, file);
	file = init_file();
	file->path = ft_strjoin(asset_files_path, "output_file_2.txt");
	file->mode = TRUNCATE;
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
		grep r > output_file_1.txt > output_file_2.txt > output_file_3.txt
	*/

	t_string asset_files_path = "assets/intermediate_files/output_files/test4/";
	t_string output_file_path = ft_strjoin(asset_files_path, "output_file_3.txt");

	char *exe_path = "grep";
	char *args[] = {exe_path, "r", NULL};
	command = create_command(exe_path, args, NULL, output_file_path);
	free(output_file_path);
	command->environment = environment;

	t_file* file = init_file();
	file->path = ft_strjoin(asset_files_path, "output_file_1.txt");
	file->mode = TRUNCATE;
	add_to_list(command->intermediate_files, file);
	file = init_file();
	file->path = ft_strjoin(asset_files_path, "output_file_2.txt");
	file->mode = TRUNCATE;
	add_to_list(command->intermediate_files, file);

	result = run_a_command(command);
	
	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}
