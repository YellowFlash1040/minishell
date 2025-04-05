/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibenne <ibenne@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/12 15:11:42 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/05 13:48:05 by ismo          ########   odam.nl         */
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
#include "non_terminals.h"

int	parse_variable(t_list *tokens, char **name, char **value)
{
	int		index;
	t_token	*token;

	if (!name || !value)
		return (FAILURE);
	index = 0;
	token = read_token(tokens, index++);
	if (!token || token->type != Word)
		return (FAILURE);
	*name = ft_strdup(token->value);
	token = read_token(tokens, index);
	if (!name || !token)
		return (free(*name), FAILURE);
	if (token->type == EndOfInput)
		return (SUCCESS);
	while (token->type == EqualSign)
		token = read_token(tokens, ++index);
	if (!token || nt_comb(tokens, &index, value) != SUCCESS)
		return (free(*name), FAILURE);
	return (SUCCESS);
}

int	parse_pipeline(t_list *tokens, t_pipeline **pipeline, t_list *env)
{
	int			depth;
	t_command	*command;
	t_token		*token;

	depth = 0;
	if (build_pipeline(pipeline) == FAILURE)
		return (FAILURE);
	while (true)
	{
		if (nt_command(tokens, &depth, &command) == FAILURE)
			return (destroy_pipeline(pipeline), FAILURE);
		command->environment = env;
		add_to_list((*pipeline)->commands, command);
		token = read_token(tokens, depth);
		if (!token)
			return (destroy_pipeline(pipeline), FAILURE);
		if (token->type == Pipe)
			depth++;
		else if (token->type == EndOfInput)
			break ;
	}
	return (SUCCESS);
}
