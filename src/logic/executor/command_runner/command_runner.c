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
#include <stdio.h>

int	setup_redirections(t_command *command);
int	launch_binary(t_command *command);
int	handle_child_process(t_command *command);
int	setup_binary_path(t_command *command);
int	print_not_found_err(t_string binary_path);
int	run_builtin(t_command *command);

int	run_a_command(t_command *command)
{
	pid_t	pid;
	int		result;

	pid = fork();
	if (pid == -1)
		return (FORK_FUNC_ERR);
	command->id = pid;
	if (pid == 0)
	{
		if (command->unused_pipe_end != -1)
		{
			result = close(command->unused_pipe_end);
			if (result == -1)
				return (CLOSE_FUNC_ERR);
		}
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
	int	result;

	result = waitpid(command->id, &exit_status, 0);
	if (result == -1)
		return (CHILD_HANDLER_ERR);
	if (WIFEXITED(exit_status))
		command->exit_status_code = WEXITSTATUS(exit_status);
	else if (WIFSIGNALED(exit_status))
		command->exit_status_code = WTERMSIG(exit_status);
	else if (WIFSTOPPED(exit_status))
		command->exit_status_code = WSTOPSIG(exit_status);
	else
		return (UNKNOWN_PROC_EXIT_STATUS_ERR);
	return (SUCCESS);
}
// printf("exit status = %d\n", command->exit_status_code);
// return (command->exit_status_code);

int	launch_binary(t_command *command)
{
	int	result;

	if (is_builtin(command->executable))
		return (run_builtin(command));
	setup_binary_path(command);
	result = execve(command->executable, command->arguments, NULL);
	if (result == -1)
	{
		if (errno == ENOENT)
		{
			result = print_not_found_err(command->executable);
			if (result != SUCCESS)
				return (result);
			return (SUCCESS);
		}
		return (perror("Error"), BINARY_LAUNCH_ERR);
	}
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
		}
		if (redirections[i].file->fd != redirections[i].standard_fd)
		{
			result = redirect(redirections[i].standard_fd,
					redirections[i].file->fd);
			if (result != SUCCESS)
				return (result);
		}
	}
	return (SUCCESS);
}

int	setup_binary_path(t_command *command)
{
	t_string	binary_path;
	int			result;

	result = find_binary(command->executable, &binary_path);
	if (result != SUCCESS)
		return (result);
	if (binary_path != NULL)
	{
		free(command->executable);
		command->executable = binary_path;
	}
	return (SUCCESS);
}
