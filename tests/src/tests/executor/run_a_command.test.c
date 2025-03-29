#include "command_runner.h"
#include "helpers.h"

t_list* environment;

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
int test11(void);
int test12(void);
int test13(void);
int test14(void);
int test15(void);
int	test16(void);
int	test17(void);
int	test18(void);
int	test19(void);
int	test20(void);
int	test21(void);

int main(int argc, char **args, char* envp[])
{
	(void)argc;
	(void)args;

	environment = init_environment(envp);

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
			test17,
			test18,

			test19,

			test20,
			test21
		};

	for (int i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++)
		run_a_test(tests[i], i + 1, false);

	destroy_environment(&environment);
}

int	test1(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/ls";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = environment;

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int	test2(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/cat";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, "assets/executor/command_runner/test2/input.txt", NULL);
	command->environment = environment;

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

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
	command->environment = environment;

	result = run_a_command(command);

	int exit_status_code;
	exit_status_code = command->exit_status_code;

	destroy_command(&command);

	if (exit_status_code != FAILURE)
		return (FAILURE);

	return (result);
}

int	test4(void)
{
	int result;
	t_command *command;

	char *exe_path = "";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = environment;

	result = run_a_command(command);

	int exit_status_code;
	exit_status_code = command->exit_status_code;

	destroy_command(&command);

	if (exit_status_code != FAILURE)
		return (FAILURE);

	return (result);
}

int	test5(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/ls";
	char *args[] = {exe_path, "--invalidoption", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = environment;

	result = run_a_command(command);

	if (command->exit_status_code != 2)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int	test6(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/grep";
	char *args[] = {exe_path, "is", NULL};
	command = create_command(exe_path, args, "assets/executor/command_runner/test8/input.txt", NULL);
	command->environment = environment;

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

	char *exe_path = "/bin/wc";
	char *args[] = {exe_path, "-l", NULL};
	command = create_command(exe_path, args, "assets/executor/command_runner/test10/input.txt", NULL);
	command->environment = environment;

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

	char *exe_path = "cowsay";
	char *args[] = {exe_path, "hello world!", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = environment;

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

	char *exe_path = "grepo";
	char *args[] = {exe_path, "h", NULL};
	command = create_command(exe_path, args, "assets/executor/command_runner/test11/input.txt", "assets/executor/command_runner/test11/output.txt");
	command->environment = environment;

	result = run_a_command(command);

	int exit_status_code;
	exit_status_code = command->exit_status_code;

	destroy_command(&command);

	if (exit_status_code != FAILURE)
		return (FAILURE);
		
	return (result);
}

int test10(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/false";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = environment;

	result = run_a_command(command);

	if (command->exit_status_code != 1)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int test11(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/true";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = environment;

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int	test12(void)
{
	int result;
	t_command *command;

	char *exe_path = "/bin/printf";
	char *args[] = {exe_path, "test", NULL};
	command = create_command(exe_path, args, NULL, "assets/executor/command_runner/test9/output.txt");
	command->environment = environment;

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = command->exit_status_code;

	destroy_command(&command);
	return (result);
}

int	test13(void)
{
	int result;
	t_command *command;

	char *exe_path = "unset";
	char *args[] = {exe_path, "PWD", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	destroy_command(&command);
	

	exe_path = "cd";
	char *args2[] = {exe_path, get_env_variable(environment, "PWD"), NULL};
	command = create_command(exe_path, args2, NULL, NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	destroy_command(&command);

	exe_path = "pwd";
	char *args3[] = {exe_path, NULL};
	command = create_command(exe_path, args3, NULL, NULL);
	command->environment = environment;

	result = run_a_command(command);

	destroy_command(&command);

	return (result);
}

int	test14(void)
{
	int result;
	t_command *command;

	char *exe_path = "unset";
	char *args[] = {exe_path, "OLDPWD", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	destroy_command(&command);
	

	exe_path = "cd";
	char *args2[] = {exe_path, "-", NULL};
	command = create_command(exe_path, args2, NULL, NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	destroy_command(&command);

	exe_path = "pwd";
	char *args3[] = {exe_path, NULL};
	command = create_command(exe_path, args3, NULL, NULL);
	command->environment = environment;

	result = run_a_command(command);

	destroy_command(&command);

	return (result);
}

// $ unset OLDPWD
// $ cd -
// bash: cd: OLDPWD not set
// $

int	test15(void)
{
	int result;
	t_command *command;

	char *exe_path = "unset";
	char *args[] = {exe_path, "PWD", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	destroy_command(&command);
	

	exe_path = "cd";
	char *args2[] = {exe_path, "..", NULL};
	command = create_command(exe_path, args2, NULL, NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	destroy_command(&command);

	exe_path = "pwd";
	char *args3[] = {exe_path, NULL};
	command = create_command(exe_path, args3, NULL, NULL);
	command->environment = environment;

	result = run_a_command(command);

	destroy_command(&command);

	return (result);
}

int	test16(void)
{
	int result;
	t_command *command;

	char *exe_path = "unset";
	char *args[] = {exe_path, "PWD", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	destroy_command(&command);
	

	exe_path = "cd";
	char *args2[] = {exe_path, "..", NULL};
	command = create_command(exe_path, args2, NULL, NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	destroy_command(&command);

	exe_path = "echo";
	char *args3[] = {exe_path, get_env_variable(environment, "PWD"), NULL};
	command = create_command(exe_path, args3, NULL, NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	destroy_command(&command);

	return (result);
}

int	test17(void)
{
	int result;
	t_command *command;

	char *exe_path = "unset";
	char *args[] = {exe_path, "PWD", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	destroy_command(&command);

	exe_path = "echo";
	char *args3[] = {exe_path, get_env_variable(environment, "PWD"), NULL};
	command = create_command(exe_path, args3, NULL, NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	destroy_command(&command);

	return (result);
}

int	save_result_to_env(t_list *env, int pipeline_status_code);

int	test18(void)
{
	int result;
	t_command *command;

	char *exe_path = "ls";
	char *args[] = {exe_path, "none_existing_dir", NULL};
	command = create_command(exe_path, args, NULL, NULL);
	command->environment = environment;

	result = run_a_command(command);

	save_result_to_env(environment, command->exit_status_code);

	if (command->exit_status_code != 2)
		result = FAILURE;

	destroy_command(&command);

	if (result != SUCCESS)
		return (result);

	exe_path = "echo";
	char *args2[] = {exe_path, get_env_variable(environment, "?"), NULL};
	command = create_command(exe_path, args2, NULL, NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	save_result_to_env(environment, command->exit_status_code);

	if (command->exit_status_code != SUCCESS)
		result = FAILURE;

	destroy_command(&command);

	if (result != SUCCESS)
		return (result);

	exe_path = "unset";
	char *args3[] = {exe_path, "?", NULL};
	command = create_command(exe_path, args3, NULL, NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	save_result_to_env(environment, command->exit_status_code);

	if (command->exit_status_code != SUCCESS)
		result = FAILURE;

	destroy_command(&command);

	if (result != SUCCESS)
		return (result);

	exe_path = "echo";
	char *args4[] = {exe_path, get_env_variable(environment, "?"), NULL};
	command = create_command(exe_path, args4, NULL, NULL);
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	save_result_to_env(environment, command->exit_status_code);

	if (command->exit_status_code != SUCCESS)
		result = FAILURE;

	destroy_command(&command);

	if (result != SUCCESS)
		return (result);

	return (result);
}

int	test19(void)
{
	int result;
	t_command *command;

	char *exe_path = "exit";
	char *args[] = {exe_path, NULL};
	command = create_command(exe_path, args, NULL, "assets/executor/command_runner/test19/test_EXIT.txt");
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = FAILURE;

	destroy_command(&command);
	return (result);
}

int	test20(void)
{
	int result;
	t_command *command;

	char *exe_path = "grep";
	char *args[] = {exe_path, "h", NULL};
	command = create_command(exe_path, args, "../input.txt", "../result.txt");
	command->environment = environment;
	command->needs_a_subshell = false;

	result = run_a_command(command);

	if (command->exit_status_code != SUCCESS)
		result = FAILURE;

	destroy_command(&command);
	return (result);
}

int	test21(void)
{
	t_string result_str = get_env_variable(environment, "not_existing_variable");
	printf("$$%s$$\n", result_str);
	return (SUCCESS);
}
