/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_redirs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/31 00:48:56 by ismo          #+#    #+#                 */
/*   Updated: 2025/03/31 02:19:34 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "global_status_codes.h"
#include "command.h"
#include "token.h"
#include "file.h"

t_write_mode get_mode(t_token_type redir_type)
{
	if (redir_type == RedirOutput)
		return (TRUNCATE);
	if (redir_type == RedirInput)
		return (READ);
	if (redir_type == RedirAppend)
		return (APPEND);
	return (NONE);
}

int	add_file_redir(t_command **command, char **filename, t_token_type redir_type)
{
	t_file *file;

	file = init_file();
	if (!(*command) || !file)
		return (0);
	file->mode = get_mode(redir_type);
	file->path = *filename;
	if (redir_type == RedirOutput || redir_type == RedirAppend)
	{
		if ((*command)->output_file)
		{
			if ((*command)->output_file->fd == STDOUT_FILENO)
				free((*command)->output_file);
			else
				add_to_list((*command)->intermediate_files, (*command)->output_file);
		}
		(*command)->output_file = file;
	}
	if (redir_type == RedirInput)
	{
		if ((*command)->input_file)
		{
			if ((*command)->input_file->fd == STDIN_FILENO)
				free((*command)->input_file);
			else
				add_to_list((*command)->intermediate_files, (*command)->input_file);
		}
		(*command)->input_file = file;
	}
	return (1);
}

