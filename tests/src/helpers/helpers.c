#include "helpers.h"

void	run_a_test(int (*test)(void), int index, bool suppress_child_output)
{
	pid_t pid;
	int result;
	int exit_status;

	pid = fork();
	if (pid == 0)
	{
		if (suppress_child_output)
		{
			int fd = open("/dev/null", O_WRONLY);
			dup2(fd, STDOUT_FILENO);
			dup2(fd, STDERR_FILENO);
			close(fd);
		}
		exit(test());
	}
	waitpid(pid, &exit_status, 0);
	if (WIFEXITED(exit_status))
		result = WEXITSTATUS(exit_status);
	else if (WIFSIGNALED(exit_status))
		result = WTERMSIG(exit_status);
	else if (WIFSTOPPED(exit_status))
		result = WSTOPSIG(exit_status);
	else
		result = FAILURE;
	printf("Test %d", index);
	if (result == SUCCESS)
		printf("\t✅\n");
	else
		printf("\t❌. Error %d\n", result);
	printf("\n");
}

void	run_a_test_with_variable(int (*test)(void* var), void* var, int index)
{
	int result;

	result = test(var);
	
	printf("Test %d", index);
	if (result == SUCCESS)
		printf("\t✅\n");
	else
		printf("\t❌. Error %d\n", result);
}

t_command	*create_command(char *exe_path, char **args, char *input_file,
		char *output_file)
{
	t_command *command;
	build_command(&command);
	setup_command(command, exe_path, args, input_file, output_file);
	return (command);
}

void	setup_command(t_command *command, char *exe_path, char **args,
		char *input_file, char *output_file)
{
	command->executable = ft_strdup(exe_path);

	int i = 0;
	while (args && args[i])
		i++;
	command->arguments = (char **)malloc(sizeof(char *) * (i + 1));
	for (int j = 0; j < i; j++)
		command->arguments[j] = ft_strdup(args[j]);
	command->arguments[i] = NULL;

	if (input_file)
	{
		t_file *input_f = init_file();
		input_f->path = ft_strdup(input_file);
		input_f->mode = READ;
		open_file(input_f);
		command->input_stream->fd = input_f->fd;
		destroy_file(&input_f);
	}

	if (output_file)
	{
		t_file *output_f = init_file();
		output_f->path = ft_strdup(output_file);
		output_f->mode = TRUNCATE;
		open_file(output_f);
		command->output_stream->fd = output_f->fd;
		destroy_file(&output_f);
	}
}
