#include "command_runner.h"
#include "helpers.h"

int	test1(void);
int test2(void);
int test3(void);
int test4(void);
int test5(void);
int test6(void);
int test7(void);
int test8(void);
int test9(void);
int test10(void);
int test11(void);
int test12(void);
int test13(void);
int test14(void);
int test15(void);
int test16(void);
int test17(void);

int main(void)
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
			test10,
			test11,
			test12,
			test13,
			test14,
			test15,
			test16,
			test17
		};

	for (int i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++)
		run_a_test(tests[i], i + 1, true);
}

int test1(void)
{
	int result;
	t_command *command;

	/*
		echo
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test2(void)
{
	int result;
	t_command *command;

	/*
		echo Hello World! How are you?
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "Hello", "World!", "How", "are", "you?", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test3(void)
{
	int result;
	t_command *command;

	/*
		echo -n Hello World! How are you?
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "-n", "Hello", "World!", "How", "are", "you?", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test4(void)
{
	int result;
	t_command *command;

	/*
		echo -n -n -n Hello World!
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "-n", "-n", "-n", "Hello", "World!", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test5(void)
{
	int result;
	t_command *command;

	/*
		echo -nnn Hello World!
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "-nnn", "Hello", "World!", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test6(void)
{
	int result;
	t_command *command;

	/*
		echo -nnnb Hello World!
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "-nnnb", "Hello", "World!", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test7(void)
{
	int result;
	t_command *command;

	/*
		echo -nnnb -n Hello World!
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "-nnnb", "-n", "Hello", "World!", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test8(void)
{
	int result;
	t_command *command;

	/*
		echo -nnnb -n Hello World! -n
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "-nnnb", "-n", "Hello", "World!", "-n", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test9(void)
{
	int result;
	t_command *command;

	/*
		echo -n -nnnb -n Hello World! -n
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "-n", "-nnnb", "-n", "Hello", "World!", "-n", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test10(void)
{
	int result;
	t_command *command;

	/*
		echo ""
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test11(void)
{
	int result;
	t_command *command;

	/*
		echo "" "" ""
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "", "", "", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test12(void)
{
	int result;
	t_command *command;

	/*
		echo "hello   world"
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "hello   world", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test13(void)
{
	int result;
	t_command *command;

	/*
		echo -n
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "-n", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test14(void)
{
	int result;
	t_command *command;

	/*
		echo -n ok > output.txt
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "-n", "ok", NULL};
	command = create_command(exe_path, args, NULL, "assets/builtins/test14/output.txt");

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test15(void)
{
	int result;
	t_command *command;

	/*
		echo < input.txt
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, "assets/builtins/test15/input.txt", NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test16(void)
{
	int result;
	t_command *command;

	/*
		echo standard fd's test
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "standard", "fd's", "test", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test17(void)
{
	int result;
	t_command *command;

	/*
		echo -n "" "" ""
	*/

	char *exe_path = "echo";
	char *args[] = {exe_path, "-n", "", "", "", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}
