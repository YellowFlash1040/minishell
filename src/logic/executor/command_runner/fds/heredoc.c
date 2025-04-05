/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:03:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/05 14:35:40 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_runner.h"
#include <readline/readline.h>

int	capture_heredoc(int pipe_fd, t_string delimiter);

int	get_a_heredoc(t_redirection *redirection, t_command *command)
{
	int	result;
	int	pipe_fd[2];

	if (redirection->file->fd != STDIN_FILENO)
		close(command->input_file->fd);
	result = pipe(pipe_fd);
	if (result == -1)
		return (result);
	result = capture_heredoc(pipe_fd[1], command->here_doc_delimiter);
	close(pipe_fd[1]);
	if (result != SUCCESS)
		return (close(pipe_fd[0]), result);
	command->input_file->fd = pipe_fd[0];
	return (SUCCESS);
}

int	capture_heredoc(int pipe_fd, t_string delimiter)
{
	t_string	line;

	line = readline("> ");
	while (line)
	{
		if (ft_strcmp(line, delimiter))
		{
			free(line);
			break ;
		}
		write(pipe_fd, line, ft_strlen(line));
		write(pipe_fd, "\n", 1);
		free(line);
		line = readline("> ");
	}
	return (SUCCESS);
}
