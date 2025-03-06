#include "command_runner.h"
#include "helpers.h"


int	test1(void);
int	test2(void);

int	main(void)
{
	run_a_test(test1, 1);
	run_a_test(test2, 2);
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
