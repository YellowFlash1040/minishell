/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_runner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/02/19 18:37:57 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/20 18:26:31 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_runner.h"

int	execute_command(t_command *command);
int	execute_builtin(t_command *command);
int	execute_external(t_command *command);
int	handle_child_process(t_command *command);

int	run_a_command(t_command *command)
{
	pid_t	pid;
	int		result;

	if (command->needs_a_subshell)
	{
		pid = fork();
		if (pid == -1)
			return (FORK_FUNC_ERR);
		command->id = pid;
		if (pid == 0)
		{
			set_handlers(ForkSignals);
			result = execute_command(command);
			if (result != SUCCESS)
				exit(result);
			exit(command->exit_status_code);
		}
		return (handle_child_process(command));
	}
	return (execute_command(command));
}

int	execute_command(t_command *command)
{
	if (is_builtin(command->executable))
		return (execute_builtin(command));
	return (execute_external(command));
}

int	handle_child_process(t_command *command)
{
	int	exit_status;
	int	result;

	result = waitpid(command->id, &exit_status, 0);
	if (result == -1)
		return (CHILD_HANDLER_ERR);
	if (WIFEXITED(exit_status))
		command->exit_status_code = WEXITSTATUS(exit_status);
	else if (WIFSIGNALED(exit_status))
	{
		command->exit_status_code = WTERMSIG(exit_status);
		if (command->exit_status_code == SIGINT)
			command->exit_status_code = 130;
		if (command->exit_status_code == SIGQUIT)
			command->exit_status_code = 131;
	}
	else if (WIFSTOPPED(exit_status))
		command->exit_status_code = WSTOPSIG(exit_status);
	else
		return (UNKNOWN_PROC_EXIT_STATUS_ERR);
	return (SUCCESS);
}
