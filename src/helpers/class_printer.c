/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:03:38 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/21 18:25:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class_printer.h"

// void	print_a_command(t_command *command, char *tabs)
// {
// 	char	*inside_tabs;

// 	inside_tabs = "  ";
// 	printf("%s{\n", tabs);
// 	printf("%s%sexe: \"%s\"\n", tabs, inside_tabs, command->executable);
// 	printf("%s%sarguments: ", tabs, inside_tabs);
// 	print_a_string_array(command->arguments, "");
// 	printf("%s%sinput file: \n", tabs, inside_tabs);
// 	print_a_file(command->input_file, inside_tabs);
// 	printf("%s%soutput file: \n", tabs, inside_tabs);
// 	print_a_file(command->output_file, inside_tabs);
// 	printf("%s%sunused pipe end: %d\n", tabs, inside_tabs,
// 		command->unused_pipe_end);
// 	printf("%s%sexit status code: %d\n", tabs, inside_tabs,
// 		command->exit_status_code);
// 	printf("%s}\n", tabs);
// }

void	print_a_file(t_file *file, char *tabs)
{
	printf("%s{\n", tabs);
	printf("%s  fd: %d\n", tabs, file->fd);
	printf("%s  path: %s\n", tabs, file->path);
	printf("%s}\n", tabs);
}

void	print_a_string_array(char **arr, char *tabs)
{
	int	i;

	printf("%s[ ", tabs);
	i = -1;
	while (arr[++i])
	{
		printf("\"%s\", ", arr[i]);
	}
	printf("NULL ]\n");
}

// pid_t			id;
// t_executable	executable;
// char			**arguments;
// char			**environment;
// t_file			*input_file;
// t_file			*output_file;
// t_file			*error_file;
// int				exit_status_code;
// int				unused_pipe_end;