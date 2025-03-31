/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibenne <ibenne@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/12 15:11:42 by ismo          #+#    #+#                 */
/*   Updated: 2025/03/31 02:25:44 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "ft_string.h"
#include "token.h"
#include "pipeline.h"
#include "command_builder.h"
#include "pipeline_builder.h"
#include "parser_utils.h"
#include "variable.h"
#include "parser.h"
#include "parse_redirs.h"
#include "global_status_codes.h"
#include "lst_to_str.h"

int nt_file(t_list *tokens, int *depth, char **blob)
{
	int			index;
	t_token		*token;

	if (!blob)
		return (FAILURE);
	index = *depth;
	token = read_token(tokens, index++);
	if (!token)
		return (FAILURE);
	if (token->type == EnvVariable)
		*blob = ft_strjoin("$", token->value);
	else if (token->type == DoubleQuote || token->type == SingleQuote)
		*blob = quote_str(token);
	else
		*blob = ft_strdup(token->value);
	*depth = index;
	if (!*blob)
		return (FAILURE);
	return (SUCCESS);
}

int	nt_comb(t_list *tokens, int *depth, char **comb)
{
	int		index;
	t_token *token;
	char	*tmpstr;
	t_list	*strlist;

	index = *depth;
	token = read_token(tokens, index);
	strlist = init_list();
	if (!strlist)
		return (FAILURE);
	while (token && is_file(token))
	{
		if (nt_file(tokens, &index, &tmpstr) == FAILURE)
			return (destroy_list(&strlist, free), FAILURE);
		if (!tmpstr)
			return (destroy_list(&strlist, free), FAILURE);
		add_to_list(strlist, tmpstr);
		if (is_whitespace(token->seperator))
			break ;
		token = read_token(tokens, index);
	}
	tmpstr = lst_to_str(&strlist);
	destroy_list(&strlist, free);
	*comb = tmpstr;
	*depth = index;
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
	if (!token || nt_file(tokens, &index, &value) == FAILURE)
		return (FAILURE);
	if (redir == RedirDelim)
	{
		(*command)->needs_a_here_doc = 1;
		(*command)->here_doc_delimiter = value;
	}
	else
		add_file_redir(command, &value, redir);
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

	if (build_command(command) == FAILURE)
		return (FAILURE);
	index = *depth;
	args = n_args(tokens, index);
	arguments = init_string_array(args + 1);
	if (!arguments)
		return (destroy_command(command), FAILURE);
	arg = 0;
	token = read_token(tokens, index);
	while (token)
	{
		if (is_redir(token))
		{
			if (nt_redir(tokens, &index, command) == FAILURE)
				return (destroy_command(command), FAILURE);
		}
		else if (is_file(token))
		{
			if (nt_comb(tokens, &index, &arguments[arg]) == FAILURE)
				return (destroy_command(command), FAILURE);
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

int	parse_variable(t_list *tokens, t_variable **var)
{
	int		index;
	char	*name;
	char	*value;
	t_token	*token;

	if (!var)
		return (FAILURE);
	index = 0;
	token = read_token(tokens, index++);
	if (!token || token->type != Word)
		return (FAILURE);
	name = ft_strdup(token->value);
	token = read_token(tokens, index++);
	token = read_token(tokens, index++);
	if (!token || !nt_file(tokens, &index, &value))
		return (FAILURE);
	*var = init_variable(name, value);
	return (SUCCESS);
}

int	parse_tokens(t_list *tokens, t_pipeline **pipeline, t_list *env)
{
	int index = 0;

	if (nt_pipeline(tokens, &index, pipeline, env) == SUCCESS)
		return (SUCCESS);
	return (FAILURE);
}
