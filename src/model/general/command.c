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

void	free_redirection(void *value);

t_command	*init_command(void)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->id = -1;
	command->executable = NULL;
	command->arguments = NULL;
	command->input_stream = NULL;
	command->output_stream = NULL;
	command->error_stream = NULL;
	command->redirections = NULL;
	command->environment = NULL;
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
		destroy_string(&command->executable);
	if (command->arguments)
		destroy_string_array(&command->arguments);
	if (command->input_stream)
		destroy_stream(&command->input_stream);
	if (command->output_stream)
		destroy_stream(&command->output_stream);
	if (command->error_stream)
		destroy_stream(&command->error_stream);
	if (command->redirections)
		destroy_list(&command->redirections, free_redirection);
	free(command);
	*command_ref = NULL;
}

void	free_redirection(void *value)
{
	t_redirection	*redirection;

	redirection = (t_redirection *)value;
	destroy_redirection(&redirection);
}
