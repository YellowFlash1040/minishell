#include "command_runner.h"
#include "helpers.h"

int	test1(void* var);

int main(int argc, t_string args[], t_string envp[])
{
	t_list* env;
	(void)argc;
	(void)args;

	env = init_environment(envp);

	int (*tests[])(void *) =
		{
			test1
		};

	for (int i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++)
		run_a_test_with_variable(tests[i], env, i + 1);

	destroy_environment(&env);
}

int test1(void* var)
{
	int			result;
	t_command	*command;
	t_list*		env;

	env = (t_list *)var;

	/*
		pwd; cd /tmp; pwd
	*/

	printf("Expected: /home/akovtune/codam/core/projects/minishell/tests\n");

	char *exe_path = "pwd";
	char *pwd1_args[] = {exe_path, NULL};
	command = create_command(exe_path, pwd1_args, NULL, NULL);
	command->needs_a_subshell = false;
	command->environment = env;

	result = run_a_command(command);
	destroy_command(&command);

	exe_path = "cd";
	char *cd_args[] = {exe_path, "/tmp", NULL};
	command = create_command(exe_path, cd_args, NULL, NULL);
	command->needs_a_subshell = false;
	command->environment = env;

	result = run_a_command(command);
	destroy_command(&command);

	printf("Expected: /tmp\n");

	exe_path = "pwd";
	char *pwd2_args[] = {exe_path, NULL};
	command = create_command(exe_path, pwd2_args, NULL, NULL);
	command->needs_a_subshell = false;
	command->environment = env;

	result = run_a_command(command);
	destroy_command(&command);

	// if (command->exit_status_code != SUCCESS)
	// 	result = command->exit_status_code;

	return (result);
}
