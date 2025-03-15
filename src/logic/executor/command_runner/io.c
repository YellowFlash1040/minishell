/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:34:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/14 14:12:34 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_runner.h"

int	setup_redirections(t_command *command);

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
