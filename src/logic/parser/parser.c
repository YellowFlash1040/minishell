/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:11:42 by ismo              #+#    #+#             */
/*   Updated: 2025/03/19 16:13:14 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "pipeline.h"
#include "command_builder.h"
#include "pipeline_builder.h"
#include "parser_utils.h"
#include "parser.h"
#include "global_status_codes.h"

// int nt_file(t_list *tokens, int *depth, char **file)
// {
// 	return (0);
// }

int nt_redir(t_list *tokens, int *depth, t_command **command)
{
	int 		index;
	t_token		*token;
	t_token_type redir;

	index = *depth;
	token = read_token(tokens, index);
	redir = token->type;
	token = read_token(tokens, ++index);
	if (!token || token->type != Word)
		return (FAILURE);
	if (redir == RedirInput)
	{
		(*command)->input_file->path = token->value;
		(*command)->output_file->mode = READ;
	}
	else if (redir == RedirOutput)
	{
		(*command)->output_file->path = token->value;
		(*command)->output_file->mode = TRUNCATE;
	}
	else if (redir == RedirAppend)
	{
		(*command)->output_file->path = token->value;
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

	index = *depth;
	if (build_command(command) == FAILURE)
		return (FAILURE);
	token = read_token(tokens, index);
	if (!token || token->type != Word)
		return (destroy_command(command), FAILURE);
	(*command)->executable = token->value;
	arguments = init_string_array(n_word_tokens(tokens, index) + 1);
	if (!arguments)
		return (destroy_command(command), FAILURE);
	arg = 0;
	while (token && token->type == Word)
	{
		arguments[arg++] = token->value;
		token = read_token(tokens, ++index);
	}
	arguments[arg] = NULL;
	(*command)->arguments = arguments;
	if (is_redir(token))
	{
		if (nt_redir(tokens, &index, command) == FAILURE)
			return (destroy_command(command), FAILURE);
		token = read_token(tokens, ++index);
	}
	if (!token || token->type == Pipe)
	{
		*depth = index;
		return (SUCCESS);
	}
	else
		return (destroy_command(command), FAILURE);
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
			break;
		(*depth)++;
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
