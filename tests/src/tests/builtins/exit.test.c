#include "command_runner.h"
#include "helpers.h"

int	test1(void);
int test2(void);
int test3(void);
int test4(void);
int test5(void);

int main()
{
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
}

int test1(void)
{
	int			result;
	t_command	*command;

	/*
		exit 3 ok
	*/

	char *exe_path = "exit";
	char *args[] = {exe_path, "3", "ok", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->needs_a_subshell = false;

	result = run_a_command(command);

	if (command->exit_status_code != FAILURE)
		return (FAILURE);

	destroy_command(&command);
	return (result);
}

int test2(void)
{
	int			result;
	t_command	*command;

	/*
		exit
	*/

	char *exe_path = "exit";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->needs_a_subshell = false;

	result = run_a_command(command);

	printf("result: %d\n", result);

	if (command->exit_status_code != SUCCESS)
		return (command->exit_status_code);

	destroy_command(&command);
	return (result);
}

int test3(void)
{
	int			result;
	t_command	*command;

	/*
		exit 3
	*/

	char *exe_path = "exit";
	char *args[] = {exe_path, "3", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->needs_a_subshell = false;

	printf("Expected: 3\n");
	result = run_a_command(command);

	printf("result: %d\n", result);

	if (command->exit_status_code != 3)
		return (FAILURE);

	destroy_command(&command);
	return (result);
}

int test4(void)
{
	int			result;
	t_command	*command;

	/*
		exit ok
	*/

	char *exe_path = "exit";
	char *args[] = {exe_path, "ok", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->needs_a_subshell = false;

	printf("Expected: 2\n");
	result = run_a_command(command);

	if (command->exit_status_code != 2)
			return (FAILURE);

	destroy_command(&command);
	return (result);
}

int test5(void)
{
	int			result;
	t_command	*command;

	/*
		exit 35ok
	*/

	char *exe_path = "exit";
	char *args[] = {exe_path, "35ok", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->needs_a_subshell = false;

	printf("Expected: 2\n");
	result = run_a_command(command);

	if (command->exit_status_code != 2)
			return (FAILURE);

	destroy_command(&command);
	return (result);
}
