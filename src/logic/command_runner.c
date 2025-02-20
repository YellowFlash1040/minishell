/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_runner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:37:57 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/19 18:38:35 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_runner.h"

int	setup_redirections(t_command *command);
int	launch_binary(t_command *command);
int	handle_child_process(t_command *command);

int	run_a_command(t_command *command)
{
	pid_t	pid;
	int		result;

	pid = fork();
	if (pid == -1)
		return (FAILURE);
	command->id = pid;
	if (CHILD_PROCESS)
	{
		result = setup_redirections(command);
		if (result != SUCCESS)
			return (result);
		return (launch_binary(command));
	}
	return (handle_child_process(command));
}

int	handle_child_process(t_command *command)
{
	int	exit_status;

	waitpid(command->id, &exit_status, 0);
	if (WIFEXITED(exit_status))
		command->exit_status_code = WEXITSTATUS(exit_status);
	else
		return (FAILURE);
	return (SUCCESS);
}

int	launch_binary(t_command *command)
{
	int	launch_result;

	launch_result = execve(command->executable, command->arguments,
			command->environment);
	if (launch_result == -1)
		return (FAILURE);
	return (SUCCESS);
}

int	setup_redirections(t_command *command)
{
	t_redirection	redirections[3];
	int				result;
	int				i;

	redirections[0] = (t_redirection){STDIN_FILENO, command->input_file};
	redirections[1] = (t_redirection){STDOUT_FILENO, command->output_file};
	redirections[2] = (t_redirection){STDERR_FILENO, command->error_file};
	i = -1;
	while (++i < 3)
	{
		if (redirections[i].file->path != NULL)
		{
			result = open_file(redirections[i].file);
			if (result != SUCCESS)
				return (result);
			result = redirect(redirections[i].standard_fd,
					redirections[i].file->fd);
			if (result != SUCCESS)
				return (result);
		}
	}
	return (SUCCESS);
}
