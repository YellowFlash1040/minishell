/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 00:48:56 by ismo              #+#    #+#             */
/*   Updated: 2025/04/09 12:35:24 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_status_codes.h"
#include "command.h"
#include "token.h"
#include "file.h"
#include "redirection_target.h"

t_write_mode	get_mode(t_token_type redir_type)
{
	if (redir_type == RedirOutput)
		return (TRUNCATE);
	if (redir_type == RedirInput)
		return (READ);
	if (redir_type == RedirAppend)
		return (APPEND);
	return (NONE);
}

int	add_heredoc_redirection(t_redirection *redir, t_command **command,
	char *delimeter)
{
	t_heredoc				*heredoc;
	t_redirection_target	*redir_target;

	redir_target = init_redirection_target();
	if (!redir_target)
		return (false);
	redir_target->type = HERE_DOC;
	heredoc = init_heredoc();
	if (!heredoc)
		return (free(redir_target), false);
	heredoc->delimiter = delimeter;
	redir_target->value = heredoc;
	redir->target = redir_target;
	redir->stream = (*command)->input_stream;
	return (true);
}

int	add_file_redir(t_redirection *redir, t_command **command,
	t_token_type redir_type, char *filename)
{
	t_file					*file;
	t_redirection_target	*redir_target;

	redir_target = init_redirection_target();
	if (!redir_target)
		return (false);
	redir_target->type = FILE_TYPE;
	file = init_file();
	if (!file)
		return (false);
	file->mode = get_mode(redir_type);
	file->path = ft_strdup(filename);
	redir_target->value = file;
	redir->target = redir_target;
	if (file->mode == READ)
		redir->stream = (*command)->input_stream;
	else if (file->mode == TRUNCATE || file->mode == APPEND)
		redir->stream = (*command)->output_stream;
	return (true);
}

int	add_redirection(t_command **command,
	char *redir_value,
	t_token_type redir_type)
{
	t_redirection			*redir;

	redir = init_redirection();
	if (!redir)
		return (false);
	if (redir_type == RedirDelim)
	{
		if (!add_heredoc_redirection(redir, command, redir_value))
			return (destroy_redirection(&redir), false);
	}
	else
	{
		if (!add_file_redir(redir, command, redir_type, redir_value))
			return (destroy_redirection(&redir), false);
	}
	if (!add_to_list((*command)->redirections, redir))
		return (destroy_redirection(&redir), false);
	return (true);
}
