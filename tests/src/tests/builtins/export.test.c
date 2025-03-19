#include "command_runner.h"
#include "helpers.h"

int	test1(void);
int	test2(void);
int	test3(void);
int	test4(void);

int main(void)
{
	int (*tests[])(void) =
		{
			test1,
			test2,
			test3,
			test4
		};

	for (int i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++)
		run_a_test(tests[i], i + 1, false);
}

int test1(void)
{
	int result;
	t_string envp[] = {NULL};
	t_list* env;
	t_command *command;

	env = init_environment(envp);
	if (!env)
		printf("Failed to create an environment\n");

	/*
		export VAR1
	*/

	char *exe_path = "export";
	char *args[] = {exe_path, "VAR1", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = env;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	t_string_array export_env = construct_environment_for_export(env);
	int i = -1;
	while (export_env[++i])
		printf("%s\n", export_env[i]);
	destroy_string_array(&export_env);

	destroy_command(&command);
	destroy_environment(&env);
	return (result);
}

int test2(void)
{
	int result;
	t_string envp[] = {NULL};
	t_list* env;
	t_command *command;

	env = init_environment(envp);
	if (!env)
		printf("Failed to create an environment\n");

	/*
		export VAR1="some data"
	*/

	char *exe_path = "export";
	char *args[] = {exe_path, "VAR1=some data", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = env;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	t_string_array export_env = construct_environment_for_export(env);
	int i = -1;
	while (export_env[++i])
		printf("%s\n", export_env[i]);
	destroy_string_array(&export_env);

	destroy_command(&command);
	destroy_environment(&env);
	return (result);
}

int test3(void)
{
	t_string envp[] = {"VAR1=here we go again", NULL};
	t_list* env;

	env = init_environment(envp);
	if (!env)
		printf("Failed to create an environment\n");

	/*
		export VAR1="no way man!"
	*/

	char *exe_path = "export";
	char *args[] = {exe_path, "VAR1=no way man!", NULL};

	t_command *command;
	int result;
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = env;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;
	destroy_command(&command);

	t_string_array export_env = construct_environment_for_export(env);
	int i = -1;
	while (export_env[++i])
		printf("%s\n", export_env[i]);
	destroy_string_array(&export_env);

	destroy_environment(&env);
	return (result);
}

int test4(void)
{
	t_string envp[] = {"VAR1=the weather is wonderful", NULL};
	t_list* env;

	env = init_environment(envp);
	if (!env)
		printf("Failed to create an environment\n");

	/*
		export VAR1
	*/

	char *exe_path = "export";
	char *args[] = {exe_path, "VAR1", NULL};

	t_command *command;
	int result;
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = env;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;
	destroy_command(&command);

	t_string_array export_env = construct_environment_for_export(env);
	int i = -1;
	while (export_env[++i])
		printf("%s\n", export_env[i]);
	destroy_string_array(&export_env);

	destroy_environment(&env);
	return (result);
}
