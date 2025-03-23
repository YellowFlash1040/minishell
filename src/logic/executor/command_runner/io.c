/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:34:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/23 17:17:13 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_runner.h"

int		setup_redirections(t_command *command);
int		setup_redirection(t_redirection *redirection, t_command *command);
bool	check_file(t_file *file);

int	setup_command_io(t_command *command)
{
	int	result;

	if (command->id != -1)
	{
		if (command->unused_pipe_end != -1)
			close(command->unused_pipe_end);
	}
	result = setup_redirections(command);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}
//"if (command->id != -1)" means that:
//if I called fork(), then I saved the pid inside the command->id 
//and it shouldn't be -1 (which it is by default),
//which means that I'm in a child process 
//and I want to close the unused end of the pipe 
//which I copied from the parent (if there is one), since I'm not gonna use it
//but if I didn't call fork()
//then I don't want to close it,
//since then it means that I am the parent process, 
//and me personally, as an "echo" command let's say,
//I don't need the read end of the next pipe, 
//since I'm not gonna read what I'm writing.
//But I need to save it for the next command I will run since it will need it
//and If I close it here, there will nothing to read from for the next command
//and that's why I have this "if (command->id != -1)" check

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
		result = setup_redirection(&redirections[i], command);
		if (result != SUCCESS || command->exit_status_code != SUCCESS)
		{
			if (command->input_file->fd != STDIN_FILENO)
				close(command->input_file->fd);
			if (command->output_file->fd != STDOUT_FILENO)
				close(command->output_file->fd);
			if (command->error_file->fd != STDERR_FILENO)
				close(command->error_file->fd);
			return (result);
		}
	}
	return (SUCCESS);
}

int setup_redirection(t_redirection *redirection, t_command *command)
{
	int	result;
	
	if (redirection->file->path != NULL)
	{
		if (!check_file(redirection->file))
		{
			command->exit_status_code = FAILURE;
			return (SUCCESS);
		}
		result = open_file(redirection->file);
		if (result != SUCCESS)
			return (result);
	}
	if (redirection->file->fd != redirection->standard_fd)
	{
		result = redirect(redirection->standard_fd,
				redirection->file->fd);
		if (result != SUCCESS)
			return (result);
	}
	return (SUCCESS);
}

bool	check_file(t_file *file)
{
	if (file->mode == READ && access(file->path, R_OK) != 0)
	{
		if (access(file->path, F_OK) != 0)
		{
			print_error_message(file->path);
			print_error_message(": No such file or directory\n");
			return (false);
		}
		else
		{
			print_error_message(file->path);
			print_error_message(": Permission denied\n");
			return (false);
		}
	}
	else if (access(file->path, W_OK) != 0)
	{
		if (access(file->path, F_OK) != 0)
			return (true);
		print_error_message(file->path);
		print_error_message(": Permission denied\n");
		return (false);
	}
	return (true);
}
