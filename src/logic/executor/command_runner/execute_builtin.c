/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_builtin.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: akovtune <akovtune@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 14:21:03 by akovtune      #+#    #+#                 */
/*   Updated: 2025/04/17 14:09:54 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "command_runner.h"

int		execute_with_exit_flow(t_command *command, int pipe_fd[2]);
int		execute_with_subshell_flow(t_command *command, int pipe_fd[2]);
int		execute_with_std_flow(t_command *command, int pipe_fd[2]);
int		setup_command_io(t_command *command, int pipe_fd[2]);
int		remember_standard_fds(int standard_fds[3]);
int		restore_standard_fds(int standard_fds[3]);
void	close_std_fd_copies(int fd_copies[3]);

int	execute_builtin(t_command *command, int pipe_fd[2])
{
	if (ft_strcmp(command->executable, "exit"))
		return (execute_with_exit_flow(command, pipe_fd));
	if (command->needs_a_subshell)
		return (execute_with_subshell_flow(command, pipe_fd));
	return (execute_with_std_flow(command, pipe_fd));
}

int	execute_with_subshell_flow(t_command *command, int pipe_fd[2])
{
	int	result;

	result = setup_command_io(command, pipe_fd);
	if (result != SUCCESS || command->exit_status_code != SUCCESS)
		return (result);
	result = launch_builtin(command);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

int	execute_with_std_flow(t_command *command, int pipe_fd[2])
{
	int	result;
	int	standard_fds[3];

	result = remember_standard_fds(standard_fds);
	if (result != SUCCESS)
		return (result);
	result = setup_command_io(command, pipe_fd);
	if (result != SUCCESS || command->exit_status_code != SUCCESS)
	{
		close_std_fd_copies(standard_fds);
		return (result);
	}
	result = launch_builtin(command);
	if (result != SUCCESS)
	{
		restore_standard_fds(standard_fds);
		return (result);
	}
	result = restore_standard_fds(standard_fds);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

int	execute_with_exit_flow(t_command *command, int pipe_fd[2])
{
	int	result;

	result = setup_command_io(command, pipe_fd);
	if (result != SUCCESS || command->exit_status_code != SUCCESS)
		return (result);
	result = launch_builtin(command);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}
