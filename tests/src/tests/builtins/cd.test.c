#include "command_runner.h"
#include "helpers.h"

int	test1(void);

int main(void)
{
	int (*tests[])(void) =
		{
			test1
		};

	for (int i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++)
		run_a_test(tests[i], i + 1, false);
}

int test1(void)
{
	int result;
	t_command *command;

	/*
		cd /home/user
	*/

	char *exe_path = "cd";
	char *args[] = {exe_path, "/home/akovtune", NULL};
	command = create_command(exe_path, args, NULL, NULL);

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}
