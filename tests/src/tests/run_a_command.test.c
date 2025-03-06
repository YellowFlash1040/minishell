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
	run_a_test(test1, 1);
	run_a_test(test2, 2);
	run_a_test(test3, 3);
	run_a_test(test4, 4);
	run_a_test(test5, 5);
	run_a_test(test6, 6);
	run_a_test(test7, 7);
	run_a_test(test8, 8);
	run_a_test(test9, 9);
	run_a_test(test10, 10);
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
