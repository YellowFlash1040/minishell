/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:54:12 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/20 14:48:51 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

t_command	*init_command(void)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->id = -1;
	command->executable = NULL;
	command->environment = NULL;
	command->arguments = NULL;
	command->input_file = NULL;
	command->output_file = NULL;
	command->error_file = NULL;
	command->exit_status_code = 0;
	command->unused_pipe_end = -1;
	command->needs_a_subshell = true;
	return (command);
}

void	destroy_command(t_command **command_ref)
{
	t_command	*command;

	if (!command_ref || !*command_ref)
		return ;
	command = *command_ref;
	if (command->executable)
		free(command->executable);
	if (command->arguments)
		destroy_string_array(&command->arguments);
	if (command->input_file)
		destroy_file(&command->input_file);
	if (command->output_file)
		destroy_file(&command->output_file);
	if (command->error_file)
		destroy_file(&command->error_file);
	free(command);
	*command_ref = NULL;
}
