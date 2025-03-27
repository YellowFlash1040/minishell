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
			test1
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
		grep h << EOF
	*/

	char *exe_path = "grep";
	char *args[] = {exe_path, "h", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = environment;
	command->here_doc_delimiter = ft_strdup("EOF");
	command->needs_a_here_doc = true;

	result = run_a_command(command);
	
	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}
