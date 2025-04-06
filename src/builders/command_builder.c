/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:44:23 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/26 14:59:19 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_builder.h"

int	build_std_streams(t_command *command);

int	build_command(t_command **command_ref)
{
	t_command	*command;
	int			result;

	if (!command_ref)
		return (EMPTY_COMMAND_REF_ERR);
	*command_ref = init_command();
	if (!*command_ref)
		return (COMMAND_INIT_ERR);
	command = *command_ref;
	result = build_std_streams(command);
	if (result != SUCCESS)
		return (result);
	command->redirections = init_list();
	if (!command->redirections)
		return (LIST_INIT_ERR);
	return (SUCCESS);
}

int	build_std_streams(t_command *command)
{
	command->input_stream = init_stream();
	if (!command->input_stream)
		return (INPUT_STREAM_INIT_ERR);
	command->input_stream->fd = STDIN_FILENO;
	command->input_stream->type = INPUT;
	command->output_stream = init_stream();
	if (!command->output_stream)
		return (OUTPUT_STREAM_INIT_ERR);
	command->output_stream->fd = STDOUT_FILENO;
	command->output_stream->type = OUTPUT;
	command->error_stream = init_stream();
	if (!command->error_stream)
		return (ERROR_STREAM_INIT_ERR);
	command->error_stream->fd = STDERR_FILENO;
	command->error_stream->type = ERROR;
	return (SUCCESS);
}
