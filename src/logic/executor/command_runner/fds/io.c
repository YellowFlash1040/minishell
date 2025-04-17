/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   io.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: akovtune <akovtune@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 12:34:37 by akovtune      #+#    #+#                 */
/*   Updated: 2025/04/17 14:09:49 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

// int		setup_redirections(t_command *command);
// int		setup_redirection(t_stream_binding *redirection,
//				t_command *command);
// int		process_file(t_file *file);
// bool	check_file(t_file *file);
// int		get_a_heredoc(t_redirection *redirection, t_command *command);
int	setup_redirections(t_command *command);
int	setup_redirection(t_stream_binding *redirection);

int	setup_command_io(t_command *command, int pipe_fd[2])
{
	int	result;

	if (command->id != -1)
	{
		if (command->unused_pipe_end != -1)
			close(command->unused_pipe_end);
	}
	result = process_redirections(command->redirections, pipe_fd);
	if (result != SUCCESS)
	{
		if (command->input_stream->fd != STDIN_FILENO)
			close(command->input_stream->fd);
		if (command->output_stream->fd != STDOUT_FILENO)
			close(command->output_stream->fd);
		if (command->error_stream->fd != STDERR_FILENO)
			close(command->error_stream->fd);
		if (result == FILE_ACCESS_ERR)
		{
			command->exit_status_code = FAILURE;
			return (SUCCESS);
		}
		return (result);
	}
	result = setup_redirections(command);
	return (result);
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
	t_stream_binding	redirections[3];
	int					result;
	int					i;

	redirections[0] = (t_stream_binding){STDIN_FILENO, command->input_stream};
	redirections[1] = (t_stream_binding){STDOUT_FILENO, command->output_stream};
	redirections[2] = (t_stream_binding){STDERR_FILENO, command->error_stream};
	i = -1;
	while (++i < 3)
	{
		result = setup_redirection(&redirections[i]);
		if (result != SUCCESS)
		{
			if (command->input_stream->fd != STDIN_FILENO)
				close(command->input_stream->fd);
			if (command->output_stream->fd != STDOUT_FILENO)
				close(command->output_stream->fd);
			if (command->error_stream->fd != STDERR_FILENO)
				close(command->error_stream->fd);
			return (result);
		}
	}
	return (SUCCESS);
}

int	setup_redirection(t_stream_binding *redirection)
{
	int	result;

	if (redirection->stream->fd != redirection->standard_fd)
	{
		result = redirect(redirection->standard_fd, redirection->stream->fd);
		if (result != SUCCESS)
			return (result);
	}
	return (SUCCESS);
}
