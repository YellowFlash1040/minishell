/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:34:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/13 19:14:19 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

int	close_all_pipes(t_list *pipes);
int	setup_redirections(t_command *command);
int	setup_redirection(t_stream_binding *redirection);

int	setup_command_io(t_command *command)
{
	int	result;

	result = process_redirections(command->redirections);
	if (result != SUCCESS)
	{
		if (command->input_stream->fd != STDIN_FILENO)
			close(command->input_stream->fd);
		if (command->output_stream->fd != STDOUT_FILENO)
			close(command->output_stream->fd);
		if (command->error_stream->fd != STDERR_FILENO)
			close(command->error_stream->fd);
		if (result == FILE_ACCESS_ERR)
		{
			command->exit_status_code = FAILURE;
			return (SUCCESS);
		}
		return (result);
	}
	result = setup_redirections(command);
	close_all_pipes(command->pipes);
	return (result);
}

int	setup_redirections(t_command *command)
{
	t_stream_binding	redirections[3];
	int					result;
	int					i;

	redirections[0] = (t_stream_binding){STDIN_FILENO, command->input_stream};
	redirections[1] = (t_stream_binding){STDOUT_FILENO, command->output_stream};
	redirections[2] = (t_stream_binding){STDERR_FILENO, command->error_stream};
	i = -1;
	while (++i < 3)
	{
		result = setup_redirection(&redirections[i]);
		if (result != SUCCESS)
		{
			if (command->input_stream->fd != STDIN_FILENO)
				close(command->input_stream->fd);
			if (command->output_stream->fd != STDOUT_FILENO)
				close(command->output_stream->fd);
			if (command->error_stream->fd != STDERR_FILENO)
				close(command->error_stream->fd);
			return (result);
		}
	}
	return (SUCCESS);
}

int	setup_redirection(t_stream_binding *redirection)
{
	int	result;

	if (redirection->stream->fd != redirection->standard_fd)
	{
		result = redirect(redirection->standard_fd, redirection->stream->fd);
		if (result != SUCCESS)
			return (result);
	}
	return (SUCCESS);
}
