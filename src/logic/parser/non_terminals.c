/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   non_terminals.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 15:56:42 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/01 16:30:59 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "token.h"
#include "pipeline.h"
#include "command_builder.h"
#include "pipeline_builder.h"
#include "parser_utils.h"
#include "parser.h"
#include "parse_redirs.h"
#include "global_status_codes.h"
#include "lst_to_str.h"

int	nt_file(t_list *tokens, int *depth, char **blob)
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
	t_token	*token;
	char	*tmpstr;
	t_list	*strlist;

	index = *depth;
	token = read_token(tokens, index);
	strlist = init_list();
	if (!strlist)
		return (FAILURE);
	while (token && is_file(token->type))
	{
		if (nt_file(tokens, &index, &tmpstr) == FAILURE)
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

int	nt_redir(t_list *tokens, int *depth, t_command **command)
{
	int				index;
	t_token			*token;
	t_token_type	redir;
	char			*value;

	index = *depth;
	token = read_token(tokens, index++);
	redir = token->type;
	if (!token || nt_comb(tokens, &index, &value) == FAILURE)
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
	t_token			*token;
	int				arg;

	if (build_command(command) != SUCCESS)
		return (FAILURE);
	index = *depth;
	(*command)->arguments = init_string_array(n_args(tokens, index) + 1);
	if (!(*command)->arguments)
		return (destroy_command(command), FAILURE);
	arg = 0;
	token = read_token(tokens, index);
	while (token && (is_redir(token->type) || is_file(token->type)))
	{
		if (is_redir(token->type)
			&& nt_redir(tokens, &index, command) != SUCCESS)
			return (destroy_command(command), FAILURE);
		if (is_file(token->type) && nt_comb(tokens, &index,
				&(*command)->arguments[arg++]) != SUCCESS)
			return (destroy_command(command), FAILURE);
		token = read_token(tokens, index);
	}
	(*command)->arguments[arg] = NULL;
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
