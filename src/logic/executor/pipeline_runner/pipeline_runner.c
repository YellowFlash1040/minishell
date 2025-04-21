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

void	set_commands_to_pipeline_mode(t_pipeline *pipeline);
int		run_commands(t_pipeline *pipeline);
int		save_result_to_env(t_list *env, int pipeline_status_code);

int	run_a_pipeline(t_pipeline *pipeline)
{
	int			result;
	t_command	*first_command;

	if (!pipeline || !pipeline->commands || !pipeline->commands->head)
		return (FAILURE);
	first_command = (t_command *)pipeline->commands->head->value;
	if (!first_command)
		return (FAILURE);
	if (pipeline->commands->count == 1 && is_builtin(first_command->executable))
		first_command->needs_a_subshell = false;
	result = create_all_pipes(pipeline->pipes, pipeline->commands->count - 1);
	if (result != SUCCESS)
		return (FAILURE);
	set_commands_to_pipeline_mode(pipeline);
	result = run_commands(pipeline);
	if (result != SUCCESS)
		return (result);
	result = save_result_to_env(first_command->environment,
			pipeline->status_code);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

void	set_commands_to_pipeline_mode(t_pipeline *pipeline)
{
	t_list_node	*node;
	t_command	*command;

	node = pipeline->commands->head;
	while (node)
	{
		command = (t_command *)node->value;
		command->pipes = pipeline->pipes;
		command->is_in_pipeline = true;
		node = node->next;
	}
}
