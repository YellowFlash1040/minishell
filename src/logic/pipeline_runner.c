/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_runner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/02/21 14:40:15 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/21 18:37:48 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipeline_runner.h"

void	setup_command_fds(t_command *command, int *prev_pipe,
			int *current_pipe);

int	run_a_pipeline(t_pipeline *pipeline)
{
	int			result;
	int			i;
	t_list_node	*node;
	t_command	*command;
	int			current_pipe[2];
	int			prev_pipe[2];

	i = -1;
	node = pipeline->commands->head;
	prev_pipe[0] = STDIN_FILENO;
	prev_pipe[1] = -1;
	while (++i < pipeline->commands->count)
	{
		if (i != pipeline->commands->count - 1)
		{
			result = pipe(current_pipe);
			if (result != SUCCESS)
				return (PIPE_FUNC_ERR);
		}
		else
		{
			current_pipe[READ_END] = -1;
			current_pipe[WRITE_END] = STDOUT_FILENO;
		}
		command = (t_command *)node->value;
		setup_command_fds(command, prev_pipe, current_pipe);
		result = run_a_command(command);
		// if (result != SUCCESS)
		// 	return (result);
		node = node->next;
		if (current_pipe[WRITE_END] != STDOUT_FILENO)
			close(current_pipe[WRITE_END]);
		if (prev_pipe[READ_END] != STDIN_FILENO)
			close(prev_pipe[READ_END]);
		prev_pipe[0] = current_pipe[0];
		prev_pipe[1] = current_pipe[1];
	}
	return (SUCCESS);
}

void	setup_command_fds(t_command *command, int *prev_pipe,
		int *current_pipe)
{
	command->input_file->fd = prev_pipe[READ_END];
	command->output_file->fd = current_pipe[WRITE_END];
	command->unused_pipe_end = current_pipe[READ_END];
}
