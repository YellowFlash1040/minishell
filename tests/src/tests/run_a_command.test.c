#include "command_runner.h"
#include "helpers.h"

int	test1(void);
int	test2(void);
int	test3(void);
int	test4(void);
int	test5(void);
int	test6(void);
int	test7(void);
int	test8(void);
int	test9(void);
int	test10(void);

int	main(void)
{
	int (*tests[])(void) =
		{
			test1,
			test2,
			test3,
			test4,
			test5,
			test6,
			test7,
			test8,
			test9, 
			test10
		};

	for (int i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++)
		run_a_test(tests[i], i + 1, true);
}

int	test1(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/ls";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	destroy_command(&command);
	return (result);
}

int	test2(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/cat";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, "assets/test2/input.txt", NULL);

	result = run_a_command(command);

	destroy_command(&command);
	return (result);
}

int	test3(void)
{
	int result;
	t_command *command;

	char *exe_path = "nonexistentcommand";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (result == BINARY_LAUNCH_ERR)
		result = SUCCESS;

	destroy_command(&command);
	return (result);
}

int	test4(void)
{
	int result;
	t_command *command;

	char *exe_path = "";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (result == BINARY_LAUNCH_ERR)
		result = SUCCESS;

	destroy_command(&command);
	return (result);
}

int	test5(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/ls";
	char *args[] = {exe_path, "--invalidoption", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (result < 10)
		result = SUCCESS;

	destroy_command(&command);
	return (result);
}

int	test6(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/false";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (result < 10)
		result = SUCCESS;

	destroy_command(&command);
	return (result);
}

int	test7(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/true";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	destroy_command(&command);
	return (result);
}

int	test8(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/grep";
	char *args[] = {exe_path, "r", NULL};
	command = create_command(exe_path, args, "assets/test8/input.txt", NULL);

	result = run_a_command(command);

	destroy_command(&command);
	return (result);
}

int	test9(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/printf";
	char *args[] = {exe_path, "test", NULL};
	command = create_command(exe_path, args, NULL, "assets/test9/output.txt");

	result = run_a_command(command);

	destroy_command(&command);
	return (result);
}

int	test10(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/wc";
	char *args[] = {exe_path, "-l", NULL};
	command = create_command(exe_path, args, "assets/test10/input.txt", NULL);

	result = run_a_command(command);

	destroy_command(&command);
	return (result);
}
