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

int	execute_command(t_command *command, int pipe_fd[2]);
int	execute_builtin(t_command *command, int pipe_fd[2]);
int	execute_external(t_command *command, int pipe_fd[2]);
int	handle_child_process(t_command *command);

int	run_a_command(t_command *command)
{
	pid_t	pid;
	int		result;
	int		pipe_fd[2];

	if (command->needs_a_subshell)
	{
		pid = fork();
		if (pid == -1)
			return (FORK_FUNC_ERR);
		command->id = pid;
		pipe(pipe_fd);
		if (pid == 0)
		{
			reset_signal_handlers_to_default();
			result = execute_command(command, pipe_fd);
			if (result != SUCCESS)
				exit(result);
			exit(command->exit_status_code);
		}
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (handle_child_process(command));
	}
	return (execute_command(command, pipe_fd));
}

int	execute_command(t_command *command, int pipe_fd[2])
{
	if (is_builtin(command->executable))
		return (execute_builtin(command, pipe_fd));
	return (execute_external(command, pipe_fd));
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
		exit_status = WTERMSIG(exit_status);
		command->exit_status_code = 128 + exit_status;
		if (exit_status == SIGINT)
			printf("\n");
		else if (exit_status == SIGQUIT)
			printf("Quit (core dumped)\n");
	}
	else if (WIFSTOPPED(exit_status))
		command->exit_status_code = WSTOPSIG(exit_status);
	else
		return (UNKNOWN_PROC_EXIT_STATUS_ERR);
	return (SUCCESS);
}
