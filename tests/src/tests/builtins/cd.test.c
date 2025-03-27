#include "command_runner.h"
#include "helpers.h"

int	test1(void* var);
int	test2(void* var);
int	test3(void* var);
int	test4(void* var);
int	test5(void* var);
int	test6(void* var);

int main(int argc, t_string args[], t_string envp[])
{
	t_list* env;
	(void)argc;
	(void)args;

	env = init_environment(envp);

	int (*tests[])(void *) =
		{
			test1,
			test2,
			test3,
			test4,
			test5,
			test6
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
		cd /tmp
	*/

	char *exe_path = "cd";
	char *args[] = {exe_path, "/tmp", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->needs_a_subshell = false;
	command->environment = env;

	printf("old: %s\n", get_env_variable(env, "PWD"));

	result = run_a_command(command);




printf("new: %s\n", get_env_variable(env, "PWD"));	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test2(void* var)
{
	int			result;
	t_command	*command;
	t_list*		env;

	env = (t_list *)var;

	/*
		cd /home/user /home/akovtune/codam
	*/

	char *exe_path = "cd";
	char *args[] = {exe_path, "/home/akovtune", "/home/akovtune/codam", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->needs_a_subshell = false;
	command->environment = env;

	printf("old: %s\n", get_env_variable(env, "PWD"));

	result = run_a_command(command);




printf("new: %s\n", get_env_variable(env, "PWD"));	if (command->exit_status_code != FAILURE)
		return (FAILURE);

	destroy_command(&command);
	return (result);
}

int test3(void* var)
{
	int			result;
	t_command	*command;
	t_list*		env;

	env = (t_list *)var;

	/*
		cd
	*/

	char *exe_path = "cd";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->needs_a_subshell = false;
	command->environment = env;

	printf("old: %s\n", get_env_variable(env, "PWD"));

	result = run_a_command(command);




printf("new: %s\n", get_env_variable(env, "PWD"));	if (command->exit_status_code != SUCCESS)
		return (command->exit_status_code);

	destroy_command(&command);
	return (result);
}

int test4(void* var)
{
	int			result;
	t_command	*command;
	t_list*		env;

	env = (t_list *)var;

	/*
		cd -
	*/

	char *exe_path = "cd";
	char *args[] = {exe_path, "-", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->needs_a_subshell = false;
	command->environment = env;

	printf("old: %s\n", get_env_variable(env, "PWD"));

	result = run_a_command(command);

	printf("new: %s\n", get_env_variable(env, "PWD"));

	if (command->exit_status_code != SUCCESS)
		return (command->exit_status_code);

	destroy_command(&command);
	return (result);
}

int test5(void* var)
{
	int			result;
	t_command	*command;
	t_list*		env;

	env = (t_list *)var;

	/*
		cd -
	*/

	char *exe_path = "cd";
	char *args[] = {exe_path, "-", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->needs_a_subshell = false;
	command->environment = env;

	printf("old: %s\n", get_env_variable(env, "PWD"));

	result = run_a_command(command);

	printf("new: %s\n", get_env_variable(env, "PWD"));

	if (command->exit_status_code != SUCCESS)
		return (command->exit_status_code);

	destroy_command(&command);
	return (result);
}

int test6(void* var)
{
	int			result;
	t_command	*command;
	t_list*		env;

	env = (t_list *)var;

	/*
		cd /home/akovtune/codam/core
	*/

	char *exe_path = "cd";
	char *args[] = {exe_path, "/home/akovtune/codam/core", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->needs_a_subshell = false;
	command->environment = env;

	printf("old: %s\n", get_env_variable(env, "PWD"));

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		return (command->exit_status_code);

	printf("new: %s\n", get_env_variable(env, "PWD"));

	destroy_command(&command);
	return (result);
}
