/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:45:21 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/13 20:04:19 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipeline_runner.h"

int		setup_and_run_command(t_command *command, int i, int commands_count);
int		setup_streams(t_command *command, int i, int commands_count);
void	wait_for_all_commands(t_list *commands);

int	run_commands(t_pipeline *pipeline)
{
	int			result;
	t_list		*commands;
	t_list_node	*node;
	t_command	*command;
	int			i;

	commands = pipeline->commands;
	node = commands->head;
	i = -1;
	while (++i < commands->count)
	{
		command = (t_command *)node->value;
		result = setup_and_run_command(command, i, commands->count);
		if (result != SUCCESS)
			return (result);
		node = node->next;
	}
	close_all_pipes(pipeline->pipes);
	wait_for_all_commands(pipeline->commands);
	pipeline->status_code = command->exit_status_code;
	return (SUCCESS);
}

int	setup_and_run_command(t_command *command, int i, int commands_count)
{
	int	result;

	result = setup_streams(command, i, commands_count);
	if (result != SUCCESS)
		return (result);
	result = run_a_command(command);
	if (result != SUCCESS)
	{
		if (command->needs_a_subshell || command->exit_status_code == SUCCESS)
			return (result);
	}
	return (SUCCESS);
}

int	setup_streams(t_command *command, int i, int commands_count)
{
	t_list	*pipes;
	t_p1pe	*pipe_to_the_left;
	t_p1pe	*pipe_to_the_right;

	pipes = command->pipes;
	if (i > 0)
		pipe_to_the_left = (t_p1pe *)get_node(i - 1, pipes)->value;
	if (i != commands_count - 1)
		pipe_to_the_right = (t_p1pe *)get_node(i, pipes)->value;
	if (i == 0)
		command->input_stream->fd = STDIN_FILENO;
	else
		command->input_stream->fd = pipe_to_the_left->read_end;
	if (i != commands_count - 1)
		command->output_stream->fd = pipe_to_the_right->write_end;
	else
		command->output_stream->fd = STDOUT_FILENO;
	return (SUCCESS);
}

void	wait_for_all_commands(t_list *commands)
{
	t_list_node	*node;
	t_command	*command;
	int			i;

	node = commands->head;
	i = -1;
	while (++i < commands->count)
	{
		command = (t_command *)node->value;
		handle_child_process(command);
		node = node->next;
	}
}
