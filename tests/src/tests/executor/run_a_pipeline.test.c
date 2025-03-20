#include "helpers.h"
#include "pipeline_runner.h"

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

int run_with_output_manipulations(int (*run_a_pipeline)(t_pipeline *p), t_pipeline *pipeline)
{
	int result;
	// bool need_output = true;
	bool need_output = false;
	// bool need_status_codes = true;
	bool need_status_codes = false;

	if (!need_output)
	{
		int saved_stdout = dup(STDOUT_FILENO);
		int saved_stderr = dup(STDERR_FILENO);
		int fd = open("/dev/null", O_WRONLY);
		dup2(fd, STDOUT_FILENO);
		dup2(fd, STDERR_FILENO);
		close(fd);
		result = run_a_pipeline(pipeline);
		dup2(saved_stdout, STDOUT_FILENO);
		close(saved_stdout);
		dup2(saved_stderr, STDERR_FILENO);
		close(saved_stderr);
	}
	else
		result = run_a_pipeline(pipeline);
	if (result != SUCCESS)
		return (result);
	if (need_status_codes)
	{
		t_command *command;
		t_list_node *node;
		node = pipeline->commands->head;
		int i = -1;
		while (++i < pipeline->commands->count)
		{
			command = (t_command *)node->value;
			printf("%s: %d\n", command->executable, command->exit_status_code);
			node = node->next;
		}
	}
	return (result);
}

int	test1(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		ls | grep r | wc -l
	*/

	char *exe1 = "/bin/ls";
	char *args1[] = {exe1, NULL};
	char *exe2 = "/bin/grep";
	char *args2[] = {exe2, "r", NULL};
	char *exe3 = "/bin/wc";
	char *args3[] = {exe3, "-l", NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe3, args3, NULL, NULL));

	result = run_with_output_manipulations(run_a_pipeline, pipeline);

	t_command*		command;
	t_list_node*	node;
	int exit_status_codes[3];
	int pipeline_length;

	pipeline_length = pipeline->commands->count;
	node = pipeline->commands->head;
	for(int i = 0; i < pipeline_length; i++)
	{
		command = (t_command *)node->value;
		exit_status_codes[i] = command->exit_status_code;
		node = node->next;
	}

	destroy_pipeline(&pipeline);

	for(int i = 0; i < pipeline_length; i++)
	{
		if (exit_status_codes[i] != SUCCESS)
			return (exit_status_codes[i]);
	}
	
	return (result);
}

int	test2(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		/bin/echo Hello | cat
	*/

	char *exe1 = "/bin/echo";
	char *args1[] = {exe1, "Hello", NULL};
	char *exe2 = "/bin/cat";
	char *args2[] = {exe2, NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));

	result = run_with_output_manipulations(run_a_pipeline, pipeline);

	t_command*		command;
	t_list_node*	node;
	int exit_status_codes[3];
	int pipeline_length;

	pipeline_length = pipeline->commands->count;
	node = pipeline->commands->head;
	for(int i = 0; i < pipeline_length; i++)
	{
		command = (t_command *)node->value;
		exit_status_codes[i] = command->exit_status_code;
		node = node->next;
	}

	destroy_pipeline(&pipeline);

	for(int i = 0; i < pipeline_length; i++)
	{
		if (exit_status_codes[i] != SUCCESS)
			return (exit_status_codes[i]);
	}
	
	return (result);
}

int	test3(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		/bin/echo "apple banana" | tr ' ' '\n' | wc -l
	*/

	char *exe1 = "/bin/echo";
	char *args1[] = {exe1, "apple banana", NULL};
	char *exe2 = "/bin/tr";
	char *args2[] = {exe2, " ", "\n", NULL};
	char *exe3 = "/bin/wc";
	char *args3[] = {exe3, "-l", NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe3, args3, NULL, NULL));

	result = run_with_output_manipulations(run_a_pipeline, pipeline);

	t_command*		command;
	t_list_node*	node;
	int exit_status_codes[3];
	int pipeline_length;

	pipeline_length = pipeline->commands->count;
	node = pipeline->commands->head;
	for(int i = 0; i < pipeline_length; i++)
	{
		command = (t_command *)node->value;
		exit_status_codes[i] = command->exit_status_code;
		node = node->next;
	}

	destroy_pipeline(&pipeline);

	for(int i = 0; i < pipeline_length; i++)
	{
		if (exit_status_codes[i] != SUCCESS)
			return (exit_status_codes[i]);
	}
	
	return (result);
}

int	test4(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		ls | /bin/invalid_cmd | wc -l
	*/

	char *exe1 = "/bin/ls";
	char *args1[] = {exe1, NULL};
	char *exe2 = "/bin/invalid_cmd";
	char *args2[] = {exe2, NULL};
	char *exe3 = "/bin/wc";
	char *args3[] = {exe3, "-l", NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe3, args3, NULL, NULL));

	result = run_with_output_manipulations(run_a_pipeline, pipeline);

	t_command*		command;
	t_list_node*	node;
	int exit_status_codes[3];
	int pipeline_length;
	pipeline_length = pipeline->commands->count;
	node = pipeline->commands->head;
	for(int i = 0; i < pipeline_length; i++)
	{
		command = (t_command *)node->value;
		if (command->id == 0)
			break;
		exit_status_codes[i] = command->exit_status_code;
		node = node->next;
	}
	destroy_pipeline(&pipeline);
	if (exit_status_codes[0] != SUCCESS)
		return (exit_status_codes[0]);
	if (exit_status_codes[1] != FAILURE)
		return (FAILURE);
	if (exit_status_codes[2] != SUCCESS)
		return (exit_status_codes[2]);
	
	return (result);
}

int	test5(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		printf "" | cat | wc -c
	*/

	char *exe1 = "/bin/printf";
	char *args1[] = {exe1, "", NULL};
	char *exe2 = "/bin/cat";
	char *args2[] = {exe2, NULL};
	char *exe3 = "/bin/wc";
	char *args3[] = {exe3, "-c", NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe3, args3, NULL, NULL));

	result = run_with_output_manipulations(run_a_pipeline, pipeline);

	t_command*		command;
	t_list_node*	node;
	int exit_status_codes[3];
	int pipeline_length;

	pipeline_length = pipeline->commands->count;
	node = pipeline->commands->head;
	for(int i = 0; i < pipeline_length; i++)
	{
		command = (t_command *)node->value;
		exit_status_codes[i] = command->exit_status_code;
		node = node->next;
	}

	destroy_pipeline(&pipeline);

	for(int i = 0; i < pipeline_length; i++)
	{
		if (exit_status_codes[i] != SUCCESS)
			return (exit_status_codes[i]);
	}
	
	return (result);
}

int	test6(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		cat /etc/passwd | grep root | wc -l
	*/

	char *exe1 = "/bin/cat";
	char *args1[] = {exe1, "/etc/passwd", NULL};
	char *exe2 = "/bin/grep";
	char *args2[] = {exe2, "root", NULL};
	char *exe3 = "/bin/wc";
	char *args3[] = {exe3, "-l", NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe3, args3, NULL, NULL));

	result = run_with_output_manipulations(run_a_pipeline, pipeline);

	t_command*		command;
	t_list_node*	node;
	int exit_status_codes[3];
	int pipeline_length;

	pipeline_length = pipeline->commands->count;
	node = pipeline->commands->head;
	for(int i = 0; i < pipeline_length; i++)
	{
		command = (t_command *)node->value;
		exit_status_codes[i] = command->exit_status_code;
		node = node->next;
	}

	destroy_pipeline(&pipeline);

	for(int i = 0; i < pipeline_length; i++)
	{
		if (exit_status_codes[i] != SUCCESS)
			return (exit_status_codes[i]);
	}

	return (result);
}

int	test7(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		/bin/echo "123 456" | sed 's/ /,/' | tr '1' '9' | cut -d',' -f2
	*/

	char *exe1 = "/bin/echo";
	char *args1[] = {exe1, "123 456", NULL};
	char *exe2 = "/bin/sed";
	char *args2[] = {exe2, "s/ /,/", NULL};
	char *exe3 = "/bin/tr";
	char *args3[] = {exe3, "1", "9", NULL};
	char *exe4 = "/bin/cut";
	char *args4[] = {exe4, "-d", ",", "-f", "2", NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe3, args3, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe4, args4, NULL, NULL));

	result = run_with_output_manipulations(run_a_pipeline, pipeline);

	t_command*		command;
	t_list_node*	node;
	int exit_status_codes[4];
	int pipeline_length;

	pipeline_length = pipeline->commands->count;
	node = pipeline->commands->head;
	for(int i = 0; i < pipeline_length; i++)
	{
		command = (t_command *)node->value;
		exit_status_codes[i] = command->exit_status_code;
		node = node->next;
	}

	destroy_pipeline(&pipeline);

	for(int i = 0; i < pipeline_length; i++)
	{
		if (exit_status_codes[i] != SUCCESS)
			return (exit_status_codes[i]);
	}

	return (result);
}

int	test8(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		/bin/echo "data" | /bin/false | cat
	*/

	char *exe1 = "/bin/echo";
	char *args1[] = {exe1, "data", NULL};
	char *exe2 = "/bin/false";
	char *args2[] = {exe2, NULL};
	char *exe3 = "/bin/cat";
	char *args3[] = {exe3, NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe3, args3, NULL, NULL));

	result = run_with_output_manipulations(run_a_pipeline, pipeline);

	t_command*		command;
	t_list_node*	node;
	int exit_status_codes[3];
	int pipeline_length;

	pipeline_length = pipeline->commands->count;
	node = pipeline->commands->head;
	for(int i = 0; i < pipeline_length; i++)
	{
		command = (t_command *)node->value;
		exit_status_codes[i] = command->exit_status_code;
		node = node->next;
	}

	destroy_pipeline(&pipeline);

	if (exit_status_codes[0] != SUCCESS)
		return (exit_status_codes[0]);
	if (exit_status_codes[1] != 1)
		return (FAILURE);
	if (exit_status_codes[2] != SUCCESS)
		return (exit_status_codes[2]);

	return (result);
}

int	test9(void)
{
	int result;
	t_pipeline* pipeline;
	t_list* env;
	t_command* command;

	t_string pwd = getcwd(NULL, 0);
	t_string envp[] = {ft_strjoin("PWD=", pwd), NULL};
	free(pwd);
	env = init_environment(envp);

	/*
		cd /home/akovtune | ls | cd - | ls
	*/

	char *exe1 = "cd";
	char *args1[] = {exe1, "/home/akovtune", NULL};
	char *exe2 = "cd";
	char *args2[] = {exe2, "/home/akovtune/codam/core/projects/minishell", NULL};
	// char *exe2 = "cd";
	// char *args2[] = {exe2, "-", NULL};
	char *exe3 = "ls";
	char *args3[] = {exe3, NULL};
	// char *exe4 = "grep";
	// char *args4[] = {exe4, "Ma", NULL};

	build_pipeline(&pipeline);

	command = create_command(exe1, args1, NULL, NULL);
	command->environment = env;
	add_to_list(pipeline->commands, command);
	command = create_command(exe2, args2, NULL, NULL);
	command->environment = env;
	add_to_list(pipeline->commands, command);
	command = create_command(exe3, args3, NULL, NULL);;
	command->environment = env;
	add_to_list(pipeline->commands, command);
	// add_to_list(pipeline->commands, create_command(exe4, args4, NULL, NULL));

	result = run_with_output_manipulations(run_a_pipeline, pipeline);

	printf("result: %d\n", result);

	if (result != SUCCESS)
		return (result);

	char* cwd = getcwd(NULL, 0);
	printf("cwd: %s\n", cwd);
	free(cwd);

	t_list_node*	node;
	int exit_status_codes[3];
	int pipeline_length;

	pipeline_length = pipeline->commands->count;
	node = pipeline->commands->head;
	for(int i = 0; i < pipeline_length; i++)
	{
		command = (t_command *)node->value;
		exit_status_codes[i] = command->exit_status_code;
		node = node->next;
	}

	destroy_pipeline(&pipeline);

	for(int i = 0; i < pipeline_length; i++)
	{
		if (exit_status_codes[i] != SUCCESS)
			return (exit_status_codes[i]);
	}

	destroy_environment(&env);

	return (result);
}

int	test10(void)
{
	int result;
	t_pipeline *pipeline;
	t_list* env;
	t_command* command;

	t_string pwd = getcwd(NULL, 0);
	t_string envp[] = {ft_strjoin("PWD=", pwd), ft_strjoin("OLDPWD=", pwd), NULL};
	free(pwd);
	env = init_environment(envp);

	/*
		cd /home/akovtune
	*/

	char *exe1 = "cd";
	char *args1[] = {exe1, "/home/akovtune", NULL};

	build_pipeline(&pipeline);

	command = create_command(exe1, args1, NULL, NULL);
	command->environment = env;
	add_to_list(pipeline->commands, command);

	result = run_with_output_manipulations(run_a_pipeline, pipeline);

	if (result != SUCCESS)
		return (result);

	char* cwd = getcwd(NULL, 0);
	printf("cwd: %s\n", cwd);
	free(cwd);

	t_list_node*	node;
	int exit_status_codes[1];
	int pipeline_length;

	pipeline_length = pipeline->commands->count;
	node = pipeline->commands->head;
	for(int i = 0; i < pipeline_length; i++)
	{
		command = (t_command *)node->value;
		exit_status_codes[i] = command->exit_status_code;
		node = node->next;
	}

	destroy_pipeline(&pipeline);

	for(int i = 0; i < pipeline_length; i++)
	{
		if (exit_status_codes[i] != SUCCESS)
			return (exit_status_codes[i]);
	}

	destroy_environment(&env);

	return (result);
}
