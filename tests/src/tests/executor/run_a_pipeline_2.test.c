#include "helpers.h"
#include "pipeline_runner.h"

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
int	test11(void);

int	main(int argc, t_string args[], t_string envp[])
{
	(void)argc;
	(void)args;
	environment = init_environment(envp);
	
	// int (*tests[])(void) =
	// {
	// 	// test1,
	// 	// test2,
	// 	// test3,
	// 	// test4,
	// 	// test5,
	// 	// test6,
	// 	// test7,
	// 	// test8,
	// 	// test9,
	// 	// test10,
	// 	test11
	// };

	// for (int i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++)
	// 	run_a_test(tests[i], i + 1, false);

	// test1();
	// test7();
	test11();
}

int run_with_output_manipulations(int (*run_a_pipeline)(t_pipeline *p), t_pipeline *pipeline)
{
	int result;
	bool need_output = true;
	// bool need_output = false;
	bool need_status_codes = true;
	// bool need_status_codes = false;

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
			printf("%s:\t%d\n", command->executable, command->exit_status_code);
			node = node->next;
		}
	}
	return (result);
}

void collect_exit_status_codes(int **exit_status_codes, t_pipeline* pipeline)
{
	t_command*		command;
	t_list_node*	node;

	*exit_status_codes = (int *)malloc(sizeof(int) * pipeline->commands->count);
	node = pipeline->commands->head;
	for(int i = 0; i < pipeline->commands->count; i++)
	{
		command = (t_command *)node->value;
		(*exit_status_codes)[i] = command->exit_status_code;
		node = node->next;
	}
}

t_list* create_commands(t_string prompt)
{
	t_list* commands;

	commands = init_list();

	t_string_array str_commands = ft_split(prompt, '|');
	int i = -1;
	while (str_commands[++i])
	{
		t_command* command;
		build_command(&command);

		t_string_array command_parts = ft_split(str_commands[i], ' ');
		command->executable = command_parts[0];
		t_list* arguments = init_list();
		int j = -1;
		while (command_parts[++j])
		{	
			if (ft_strcmp(command_parts[j], "<"))
			{
				j++;
				command->input_file->path = command_parts[j];
			}
			else if (ft_strcmp(command_parts[j], ">"))
			{
				j++;
				command->output_file->path = command_parts[j];
			}
			else if (command_parts[j][0] == '"' && command_parts[j][ft_strlen(command_parts[j]) - 1] != '"')
			{
				int x = j + 1;
				while (command_parts[x][ft_strlen(command_parts[x]) - 1] != '"')
				{
					command_parts[j] = ft_strjoin(command_parts[j], " ");
					command_parts[j] = ft_strjoin(command_parts[j], command_parts[x]);
					x++;
				}
				command_parts[j] = ft_strjoin(command_parts[j], " ");
				command_parts[j] = ft_strjoin(command_parts[j], command_parts[x]);
				add_to_list(arguments, command_parts[j]);
				j = x + 1;
			}
			else if (command_parts[j][0] == '\'' && command_parts[j][ft_strlen(command_parts[j]) - 1] != '\'')
			{
				int x = j + 1;
				while (command_parts[x][ft_strlen(command_parts[x]) - 1] != '\'')
				{
					command_parts[j] = ft_strjoin(command_parts[j], " ");
					command_parts[j] = ft_strjoin(command_parts[j], command_parts[x]);
					x++;
				}
				command_parts[j] = ft_strjoin(command_parts[j], " ");
				command_parts[j] = ft_strjoin(command_parts[j], command_parts[x]);
				replace(command_parts[j], '\'', '\n');
				add_to_list(arguments, command_parts[j]);
				j = x + 1;
			}
			else
				add_to_list(arguments, command_parts[j]);
		}
		command->arguments = init_string_array(arguments->count);
		t_list_node* node = arguments->head;
		j = 0;
		while (node)
		{
			command->arguments[j++] = ft_strdup((t_string)node->value);
			node = node->next;
		}
		command->environment = environment;
		add_to_list(commands, command);
	}
	return (commands);
}

int run_pipeline_test(t_string prompt, int* expected_status_codes)
{
	t_pipeline *pipeline;
	int*		exit_status_codes;

	pipeline = init_pipeline();

	pipeline->commands = create_commands(prompt);

	t_list_node* node = pipeline->commands->head;
	while (node)
	{
		t_command* command_node = (t_command *)node->value;
		(void)command_node;
		node = node->next;
	}

	int result = run_with_output_manipulations(run_a_pipeline, pipeline);
	
	collect_exit_status_codes(&exit_status_codes, pipeline);

	for(int i = 0; i < pipeline->commands->count; i++)
	{
		if (exit_status_codes[i] != expected_status_codes[i])
			return (exit_status_codes[i]);
	}

	free(exit_status_codes);
	destroy_pipeline(&pipeline);

	return (result);
}

int	test1(void)
{
	/*
		ls | grep r | wc -l
	*/

	t_string prompt = "ls | grep r | wc -l";
	int		expected_status_codes[] = {SUCCESS, SUCCESS, SUCCESS};
	
	return (run_pipeline_test(prompt, expected_status_codes));
}

int	test2(void)
{
	/*
		/bin/echo Hello | cat
	*/

	t_string prompt = "echo Hello | cat";
	int expected_status_codes[] = {SUCCESS, SUCCESS, SUCCESS};
	
	return (run_pipeline_test(prompt, expected_status_codes));
}

int	test3(void)
{
	/*
		/bin/echo "apple banana" | tr ' ' '\n' | wc -l
	*/

	t_string prompt = "echo \"apple banana\" | tr ' ' '\n' | wc -l";
	int expected_status_codes[] = {SUCCESS, SUCCESS, SUCCESS};
	
	return (run_pipeline_test(prompt, expected_status_codes));
}

int	test4(void)
{
	/*
		ls | /bin/invalid_cmd | wc -l
	*/

	t_string prompt = "ls | invalid_cmd | wc -l";
	int expected_status_codes[] = {SUCCESS, FAILURE, SUCCESS};
	
	return (run_pipeline_test(prompt, expected_status_codes));
}

int	test5(void)
{
	/*
		printf "" | cat | wc -c
	*/

	t_string prompt = "printf \"\" | cat | wc -c";
	int expected_status_codes[] = {SUCCESS, SUCCESS, SUCCESS};
	
	return (run_pipeline_test(prompt, expected_status_codes));
}

int	test6(void)
{
	/*
		cat /etc/passwd | grep root | wc -l
	*/

	t_string prompt = "cat /etc/passwd | grep root | wc -l";
	int expected_status_codes[] = {SUCCESS, SUCCESS, SUCCESS};
	
	return (run_pipeline_test(prompt, expected_status_codes));
}

int	test7(void)
{
	/*
		/bin/echo "123 456" | sed 's/ /,/' | tr '1' '9' | cut -d',' -f2
	*/

	t_string prompt = "echo \"123 456\" | sed 's/ /,/' | tr '1' '9' | cut -d, -f2";
	int expected_status_codes[] = {SUCCESS, SUCCESS, SUCCESS, SUCCESS};
	
	return (run_pipeline_test(prompt, expected_status_codes));
}

int	test8(void)
{
	/*
		/bin/echo "data" | /bin/false | cat
	*/

	t_string prompt = "echo \"data\" | false | cat";
	int expected_status_codes[] = {SUCCESS, FAILURE, SUCCESS};
	
	return (run_pipeline_test(prompt, expected_status_codes));
}

int	test9(void)
{
	/*
		cd /home/akovtune | ls
	*/

	t_string prompt = "cd /home/akovtune | ls";
	int expected_status_codes[] = {SUCCESS, SUCCESS};
	
	int result = run_pipeline_test(prompt, expected_status_codes);

	t_string pwd = getcwd(NULL, 0);
	printf("pwd: %s\n", pwd);
	free(pwd);

	return (result);
}

int	test10(void)
{
	/*
		cd /home/akovtune
	*/

	t_string prompt = "cd /home/akovtune";
	int expected_status_codes[] = {SUCCESS};
	
	int result = run_pipeline_test(prompt, expected_status_codes);

	t_string pwd = getcwd(NULL, 0);
	printf("pwd: %s\n", pwd);
	free(pwd);

	return (result);
}

int	test11(void)
{
	/*
		ls ou; echo $?; unset ?; echo $?
	*/

	t_string prompt = "ls ou | wc -l";
	int expected_status_codes[] = {SUCCESS};
	
	int result = run_pipeline_test(prompt, expected_status_codes);
	printf("pid: %d\n", getpid());
	// if (result != SUCCESS)
	// 	return (result);

	printf("$? = %s\n", get_env_variable(environment, "?"));

	prompt = "unset ?";
	int expected_status_codes2[] = {SUCCESS};
	
	result = run_pipeline_test(prompt, expected_status_codes2);

	printf("$? = %s\n", get_env_variable(environment, "?"));

	return (result);
}
