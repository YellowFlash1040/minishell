/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibenne <ibenne@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/12 15:11:42 by ismo          #+#    #+#                 */
/*   Updated: 2025/03/24 16:37:29 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "token.h"
#include "pipeline.h"
#include "command_builder.h"
#include "pipeline_builder.h"
#include "parser_utils.h"
#include "parser.h"
#include "global_status_codes.h"

int nt_file(t_list *tokens, int *depth, char **blob, char *parsable)
{
	int			index;
	t_token		*token;

	if (!blob)
		return (FAILURE);
	index = *depth;
	token = read_token(tokens, index++);
	if (!token)
		return (FAILURE);
	if (parsable && (token->type == DoubleQuote || token->type == Word || token->type == EnvVariable))
		*parsable = 1;
	else if (parsable)
		*parsable = 0;
	if (token->type == EnvVariable)
		*blob = ft_strjoin("$", token->value);
	else
		*blob = ft_strdup(token->value);
	*depth = index;
	if (!*blob)
		return (FAILURE);
	return (SUCCESS);
}

int nt_redir(t_list *tokens, int *depth, t_command **command)
{
	int 		index;
	t_token		*token;
	t_token_type redir;
	char		*value;

	index = *depth;
	token = read_token(tokens, index++);
	redir = token->type;
	if (!token || nt_file(tokens, &index, &value, &(*command)->is_redir_parsable) == FAILURE)
		return (FAILURE);
	if (redir == RedirInput)
	{
		(*command)->input_file->path = value;
		(*command)->input_file->mode = READ;
	}
	else if (redir == RedirOutput)
	{
		(*command)->output_file->path = value;
		(*command)->output_file->mode = TRUNCATE;
	}
	else if (redir == RedirAppend)
	{
		(*command)->output_file->path = value;
		(*command)->output_file->mode = APPEND;
	}
	*depth = index;
	return (SUCCESS);
}

int	nt_command(t_list *tokens, int *depth, t_command **command)
{
	int				index;
	t_token 		*token;
	int				arg;
	t_string_array	arguments;
	int				args;
	int				has_redir;

	has_redir = 0;
	if (build_command(command) == FAILURE)
		return (FAILURE);
	index = *depth;
	args = n_args(tokens, index);
	arguments = init_string_array(args + 1);
	if (!arguments)
		return (destroy_command(command), FAILURE);
	(*command)->parsable = (char *)malloc(args);
	if (!(*command)->parsable)
		return (destroy_command(command), FAILURE);
	arg = 0;
	token = read_token(tokens, index);
	while (token && token->type != EndOfInput)
	{
		if (!has_redir && is_redir(token))
		{
			if (nt_redir(tokens, &index, command) == FAILURE)
				return (destroy_command(command), FAILURE);
			has_redir = 1;
		}
		else if (is_file(token))
		{
			if (nt_file(tokens, &index, arguments + arg, (*command)->parsable + arg) == FAILURE)
				return (destroy_command(command), FAILURE);
			if (arg == 0)
				(*command)->executable = ft_strdup(arguments[0]);
			arg++;
		}
		else
			break ;
		token = read_token(tokens, index);
	}
	arguments[arg] = NULL;
	(*command)->arguments = arguments;
	*depth = index;
	return (SUCCESS);
}

int	nt_pipeline(t_list *tokens, int *depth, t_pipeline **pipeline, t_list *env)
{
	t_command	*command;
	t_token		*token;

	if (build_pipeline(pipeline) == FAILURE)
		return (FAILURE);
	while (true)
	{
		if (nt_command(tokens, depth, &command) == FAILURE)
			return (destroy_pipeline(pipeline), FAILURE);
		command->environment = env;
		add_to_list((*pipeline)->commands, command);
		token = read_token(tokens, *depth);
		if (!token)
			return (destroy_pipeline(pipeline), FAILURE);
		if (token->type == Pipe)
			(*depth)++;
		else if (token->type == EndOfInput)
			break ;
	}
	return (SUCCESS);
}

int	parse_tokens(t_list *tokens, t_pipeline **pipeline, t_list *env)
{
	int index = 0;

	if (nt_pipeline(tokens, &index, pipeline, env) == SUCCESS)
		return (SUCCESS);
	return (FAILURE);
}
