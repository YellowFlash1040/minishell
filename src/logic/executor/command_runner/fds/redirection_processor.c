/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirection_processor.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akovtune <akovtune@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/26 12:40:49 by akovtune      #+#    #+#                 */
/*   Updated: 2025/04/17 14:12:39 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

int	process_redirection(t_redirection *redirection, int pipe_fd[2]);
int	get_target_fd(t_redirection_target *target, int *fd, int pipe_fd[2]);
int	setup_stream(t_stream *stream, int fd);

int	process_redirections(t_list *redirections, int pipe_fd[2])
{
	int				result;
	t_list_node		*node;
	t_redirection	*redirection;
	int				i;

	node = redirections->head;
	i = -1;
	while (++i < redirections->count)
	{
		redirection = (t_redirection *)node->value;
		result = process_redirection(redirection, pipe_fd);
		if (result != SUCCESS)
			return (result);
		node = node->next;
	}
	return (SUCCESS);
}

int	process_redirection(t_redirection *redirection, int pipe_fd[2])
{
	int						result;
	int						fd;

	result = get_target_fd(redirection->target, &fd, pipe_fd);
	if (result != SUCCESS)
		return (result);
	result = setup_stream(redirection->stream, fd);
	if (result != SUCCESS)
		return (close(fd), result);
	return (SUCCESS);
}

int	get_target_fd(t_redirection_target *target, int *fd, int pipe_fd[2])
{
	int			result;
	t_file		*file;
	t_heredoc	*heredoc;

	*fd = -1;
	if (target->type == FILE_TYPE)
	{
		file = (t_file *)target->value;
		result = process_file(file);
		if (result != SUCCESS)
			return (result);
		*fd = file->fd;
	}
	else if (target->type == HERE_DOC)
	{
		heredoc = (t_heredoc *)target->value;
		result = process_heredoc(heredoc, pipe_fd);
		if (result != SUCCESS)
			return (result);
		*fd = heredoc->fd;
	}
	return (SUCCESS);
}

int	setup_stream(t_stream *stream, int fd)
{
	int			standard_fd;

	if (stream->type == INPUT)
		standard_fd = STDIN_FILENO;
	else if (stream->type == OUTPUT)
		standard_fd = STDOUT_FILENO;
	else if (stream->type == ERROR)
		standard_fd = STDERR_FILENO;
	else
		return (FAILURE);
	if (stream->fd != standard_fd)
		close(stream->fd);
	stream->fd = fd;
	return (SUCCESS);
}
