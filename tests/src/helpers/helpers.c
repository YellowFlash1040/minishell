#include "helpers.h"

void	run_a_test(int (*test)(void), int index)
{
	int result;

	result = test();
	printf("Test %d ", index);
	if (result == SUCCESS)
		printf("✅\n");
	else
		printf("❌. Error %d\n", result);
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
		command->input_file->path = ft_strdup(input_file);
		command->input_file->mode = READ;
	}

	if (output_file)
	{
		command->output_file->path = ft_strdup(output_file);
		command->output_file->mode = TRUNCATE;
	}
}

char	*ft_strdup(const char *s)
{
	char *dup;
	int i;

	i = 0;
	while (s[i])
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}
