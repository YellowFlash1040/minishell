/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:21:03 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/20 14:25:54 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_runner.h"

int	execute_in_a_subshell(t_command *command);
int	execute_without_a_subshell(t_command *command);
int	setup_command_io(t_command *command);
int	remember_standard_fds(int standard_fds[3]);
int	restore_standard_fds(int standard_fds[3]);

int	execute_builtin(t_command *command)
{
	if (ft_strcmp(command->executable, "exit"))
		return (launch_builtin(command));
	if (command->needs_a_subshell)
		return (execute_in_a_subshell(command));
	return (execute_without_a_subshell(command));
}

int	execute_in_a_subshell(t_command *command)
{
	int	result;

	result = setup_command_io(command);
	if (result != SUCCESS)
		return (result);
	result = launch_builtin(command);
	if (result != SUCCESS)
		return (result);
	exit (SUCCESS);
}

int	execute_without_a_subshell(t_command *command)
{
	int	result;
	int	standard_fds[3];

	result = remember_standard_fds(standard_fds);
	if (result != SUCCESS)
		return (result);
	result = setup_command_io(command);
	if (result != SUCCESS)
		return (result);
	result = launch_builtin(command);
	if (result != SUCCESS)
		return (result);
	result = restore_standard_fds(standard_fds);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

int	remember_standard_fds(int standard_fds[3])
{
	int	result;

	result = dup(STDIN_FILENO);
	if (result == -1)
		return (FAILURE);
	standard_fds[0] = result;
	result = dup(STDOUT_FILENO);
	if (result == -1)
		return (close(standard_fds[0]), FAILURE);
	standard_fds[1] = result;
	result = dup(STDERR_FILENO);
	if (result == -1)
		return (close(standard_fds[0]), close(standard_fds[1]), FAILURE);
	standard_fds[2] = result;
	return (SUCCESS);
}

int	restore_standard_fds(int standard_fds[3])
{
	int	result;

	result = redirect(STDIN_FILENO, standard_fds[0]);
	if (result == -1)
		return (FAILURE);
	result = redirect(STDOUT_FILENO, standard_fds[1]);
	if (result == -1)
		return (FAILURE);
	result = redirect(STDERR_FILENO, standard_fds[2]);
	if (result == -1)
		return (FAILURE);
	return (SUCCESS);
}
