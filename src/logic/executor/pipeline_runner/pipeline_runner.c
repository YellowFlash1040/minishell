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

int		run_commands(t_list *commands, int prev_pipe[2], int current_pipe[2],
			int *pipeline_status_code);
int		setup_current_pipe(int current_pipe[2], int i, int commands_count);
int		setup_and_run_command(t_command *command, int prev_pipe[2],
			int current_pipe[2]);
int		move_to_the_next_pipe(int prev_pipe[2], int current_pipe[2]);
int		save_result_to_env(t_list *env, int pipeline_status_code);

int	run_a_pipeline(t_pipeline *pipeline)
{
	int			result;
	int			prev_pipe[2];
	int			current_pipe[2];
	t_command	*first_command;

	if (!pipeline || !pipeline->commands || !pipeline->commands->head)
		return (FAILURE);
	first_command = (t_command *)pipeline->commands->head->value;
	if (!first_command)
		return (FAILURE);
	if (pipeline->commands->count == 1 && is_builtin(first_command->executable))
		first_command->needs_a_subshell = false;
	result = run_commands(pipeline->commands, prev_pipe, current_pipe,
			&pipeline->status_code);
	if (result != SUCCESS)
		return (result);
	result = save_result_to_env(first_command->environment,
			pipeline->status_code);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

int	run_commands(t_list *commands, int prev_pipe[2], int current_pipe[2],
	int *pipeline_status_code)
{
	int			result;
	t_list_node	*node;
	t_command	*command;
	int			i;

	node = commands->head;
	prev_pipe[0] = STDIN_FILENO;
	prev_pipe[1] = -1;
	i = -1;
	while (++i < commands->count)
	{
		command = (t_command *)node->value;
		result = setup_current_pipe(current_pipe, i, commands->count);
		if (result != SUCCESS)
			return (result);
		result = setup_and_run_command(command, prev_pipe, current_pipe);
		if (result != SUCCESS || command->id == 0)
			return (result);
		result = move_to_the_next_pipe(prev_pipe, current_pipe);
		if (result != SUCCESS)
			return (result);
		node = node->next;
	}
	*pipeline_status_code = command->exit_status_code;
	return (SUCCESS);
}

int	setup_and_run_command(t_command *command, int prev_pipe[2],
		int current_pipe[2])
{
	int	result;

	command->input_file->fd = prev_pipe[READ_END];
	command->output_file->fd = current_pipe[WRITE_END];
	command->unused_pipe_end = current_pipe[READ_END];
	result = run_a_command(command);
	if (result != SUCCESS)
	{
		if (command->needs_a_subshell || command->exit_status_code == SUCCESS)
			return (result);
	}
	return (SUCCESS);
}

int	setup_current_pipe(int current_pipe[2], int i, int commands_count)
{
	int	result;

	if (i != commands_count - 1)
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
	return (SUCCESS);
}

int	move_to_the_next_pipe(int prev_pipe[2], int current_pipe[2])
{
	if (current_pipe[WRITE_END] != STDOUT_FILENO)
		close(current_pipe[WRITE_END]);
	if (prev_pipe[READ_END] != STDIN_FILENO)
		close(prev_pipe[READ_END]);
	prev_pipe[0] = current_pipe[0];
	prev_pipe[1] = current_pipe[1];
	return (SUCCESS);
}

