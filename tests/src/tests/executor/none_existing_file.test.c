#include "command_runner.h"
#include "helpers.h"

t_list* environment;

int	test1(void);
int	test2(void);
int	test3(void);
int	test4(void);
int	test5(void);
int	test6(void);
int	test7(void);
int	test8(void);

int main(int argc, char **args, char* envp[])
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
			test5,
			test6,
			test7,
			test8
		};

	for (int i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++)
		run_a_test(tests[i], i + 1, false);

	// test1();
	// test3();

	destroy_environment(&environment);
}

int	test1(void)
{
	int result;
	t_command *command;

	/*
		echo < none_existing_file.txt
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, "none_existing_file.txt", NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	if (command->exit_status_code != FAILURE)
		result = FAILURE;

	destroy_command(&command);
	return (result);
}

int	test2(void)
{
	int result;
	t_command *command;

	/*
		echo test2 > none_existing_output_file2.txt
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "test2", NULL};
	command = create_command(exe_path, args, NULL, "assets/executor/none_existing_file/none_existing_output_file2.txt");
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = FAILURE;

	destroy_command(&command);
	return (result);
}

int	test3(void)
{
	int result;
	t_command *command;

	/*
		echo test3 < none_existing_file.txt > none_existing_output_file3.txt
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "test3", NULL};
	command = create_command(exe_path, args, "none_existing_file.txt", "assets/executor/none_existing_file/none_existing_output_file3.txt");
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	if (command->exit_status_code != FAILURE)
		result = FAILURE;

	destroy_command(&command);
	return (result);
}

int	test4(void)
{
	int result;
	t_command *command;

	/*
		Same as test number 1, but this time it runs in a subshell
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, "none_existing_file.txt", NULL);
	command->environment = environment;

	result = run_a_command(command);

	if (command->exit_status_code != FAILURE)
		result = FAILURE;

	destroy_command(&command);
	return (result);
}

int	test5(void)
{
	int result;
	t_command *command;

	/*
		echo test5 > none_existing_output_file5.txt
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "test5", NULL};
	command = create_command(exe_path, args, NULL, "assets/executor/none_existing_file/none_existing_output_file5.txt");
	command->environment = environment;

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = FAILURE;

	destroy_command(&command);
	return (result);
}

int	test6(void)
{
	int result;
	t_command *command;

	/*
		echo < none_existing_file.txt > none_existing_output_file6.txt
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, "none_existing_file.txt", "assets/executor/none_existing_file/none_existing_output_file6.txt");
	command->environment = environment;

	result = run_a_command(command);

	if (command->exit_status_code != FAILURE)
		result = FAILURE;

	destroy_command(&command);
	return (result);
}

int	test7(void)
{
	int result;
	t_command *command;

	/*
		grep r < none_existing_file.txt
	*/

	char *exe_path = "grep";
	char *args[] = {exe_path, "r", NULL};
	command = create_command(exe_path, args, "none_existing_file.txt", NULL);
	command->environment = environment;

	result = run_a_command(command);

	if (command->exit_status_code != FAILURE)
		result = FAILURE;

	destroy_command(&command);
	return (result);
}

int	test8(void)
{
	int result;
	t_command *command;

	/*
		exit < none_existing_file.txt
	*/

	char *exe_path = "exit";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, "none_existing_file.txt", NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	if (command->exit_status_code != FAILURE)
		result = FAILURE;

	destroy_command(&command);
	return (result);
}
