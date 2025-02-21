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
	return (command);
}

void	destroy_command(t_command **command)
{
	t_command	*command_v;

	if (!command || !*command)
		return ;
	command_v = *command;
	if (command_v->executable)
		free(command_v->executable);
	if (command_v->arguments)
		free_array(command_v->arguments);
	if (command_v->environment)
		free_array(command_v->environment);
	if (command_v->input_file)
		destroy_file(&command_v->input_file);
	if (command_v->output_file)
		destroy_file(&command_v->output_file);
	if (command_v->error_file)
		destroy_file(&command_v->error_file);
	free(command_v);
	*command = NULL;
}
