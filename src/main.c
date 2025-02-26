/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:03:52 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/26 14:59:34 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "error_printer.h"
// #include "parser.h"

// int	main(int argsc, char **args)
// {
// 	int			result;
// 	t_prompt	*prompt;

// 	if (argsc < 1)
// 		return (FAILURE);
// 	result = parse(args[1], &prompt);
// 	if (result != SUCCESS)
// 		return (result);
// 	destroy_prompt(&prompt);
// 	return (SUCCESS);
// }

#include "class_printer.h"
#include "command_builder.h"
#include "converter.h"
#include "pipeline_builder.h"
#include "pipeline_runner.h"
#include <stdio.h>

char	*ft_strdup(const char *s);
char	**create_arguments(char *exe_path);
char	**create_envp(char *envp[]);
void	setup_command_1(t_command *command, char *envp[]);
void	setup_command_2(t_command *command, char *envp[]);
void	setup_command_3(t_command *command, char *envp[]);

int	main(int argc, char *argv[], char *envp[])
{
	int			result;
	t_pipeline	*pipeline;
	t_command	*cmd1;
	t_command	*cmd2;
	t_command	*cmd3;

	(void)argc;
	(void)argv;
	build_pipeline(&pipeline);
	build_command(&cmd1);
	build_command(&cmd2);
	build_command(&cmd3);
	setup_command_1(cmd1, envp);
	setup_command_2(cmd2, envp);
	setup_command_3(cmd3, envp);
	add_to_list(pipeline->commands, cmd1);
	add_to_list(pipeline->commands, cmd2);
	add_to_list(pipeline->commands, cmd3);
	result = run_a_pipeline(pipeline);
	if (result != SUCCESS)
		printf("Something went wrong. Error %d\n", result);
	// printf("cmd1:\n");
	// print_a_command(cmd1, "");
	// printf("cmd2:\n");
	// print_a_command(cmd2, "");
	// printf("cmd3:\n");
	// print_a_command(cmd3, "");
	destroy_pipeline(&pipeline);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	while (s[i])
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**create_envp(char *envp[])
{
	t_list	*list;
	char	**env;
	int		i;
	bool	success;
	char	*string;

	list = init_list();
	i = -1;
	while (envp[++i])
	{
		string = ft_strdup(envp[i]);
		if (!string)
			clear_list(list, free);
		success = add_to_list(list, string);
		if (!success)
			clear_list(list, free);
	}
	env = convert_list_to_array(list);
	clear_list(list, NULL);
	return (env);
}

void	setup_command_1(t_command *command, char *envp[])
{
	char	*exe_path;

	exe_path = "/bin/ls";
	command->executable = ft_strdup(exe_path);
	command->arguments = (char **)malloc(sizeof(char *) * (1 + 1));
	command->arguments[0] = ft_strdup(exe_path);
	command->arguments[1] = NULL;
	command->environment = create_envp(envp);
}

void	setup_command_2(t_command *command, char *envp[])
{
	char	*exe_path;

	exe_path = "/bin/grep";
	command->executable = ft_strdup(exe_path);
	command->arguments = (char **)malloc(sizeof(char *) * (2 + 1));
	command->arguments[0] = ft_strdup(exe_path);
	command->arguments[1] = ft_strdup("r");
	command->arguments[2] = NULL;
	command->environment = create_envp(envp);
	// command->output_file->path = ft_strdup("output.txt");
	// command->output_file->mode = TRUNCATE;
}

void	setup_command_3(t_command *command, char *envp[])
{
	char	*exe_path;

	exe_path = "/bin/wc";
	command->executable = ft_strdup(exe_path);
	command->arguments = (char **)malloc(sizeof(char *) * (2 + 1));
	command->arguments[0] = ft_strdup(exe_path);
	command->arguments[1] = ft_strdup("-l");
	command->arguments[2] = NULL;
	command->environment = create_envp(envp);
	command->output_file->path = ft_strdup("output.txt");
	command->output_file->mode = TRUNCATE;
}

// Example 1
// ARG=hello; OK=hello;  echo ARG; ls | cat name.txt
//&&git log;

// Example 2
// ls | grep ok<input.txt<input2.txt> output2.txt> output.txt | wc - l;

// Example 3
// ARG = ok;
// echo	hello;
// echo ARG
// ls  >output.txt
// echo $?

// Example 4
// ARG=hello; OK="how are you?"; FILE=input.txt; echo $OK; cat $FILE; ls | grep $OK > $FILE
// export OK="how are you?"
// unset
