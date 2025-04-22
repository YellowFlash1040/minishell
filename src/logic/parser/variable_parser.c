/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:16:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/22 19:05:57 by akovtune         ###   ########.fr       */
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

int	parse_name(t_list *tokens, char **name);
int	parse_value(t_list *tokens, int index, char **value);
int	handle_no_value(char **value);

int	parse_variable(t_list *tokens, char **name, char **value)
{
	int		index;
	t_token	*token;

	if (!name || !value)
		return (FAILURE);
	if (parse_name(tokens, name) != SUCCESS)
		return (FAILURE);
	index = 1;
	token = read_token(tokens, index);
	if (!token)
		return (free(*name), FAILURE);
	if (token->type == EndOfInput)
	{
		*value = NULL;
		return (SUCCESS);
	}
	if (parse_value(tokens, index, value) != SUCCESS)
		return (free(*name), FAILURE);
	return (SUCCESS);
}

int	parse_name(t_list *tokens, char **name)
{
	t_token	*token;

	token = read_token(tokens, 0);
	if (!token || token->type != Word)
		return (FAILURE);
	*name = ft_strdup(token->value);
	if (!*name)
		return (FAILURE);
	return (SUCCESS);
}

int	parse_value(t_list *tokens, int index, char **value)
{
	t_token	*token;

	token = read_token(tokens, index);
	while (token && token->type == EqualSign)
	{
		index++;
		token = read_token(tokens, index);
	}
	if (!token || token->type == EndOfInput)
		return (handle_no_value(value));
	if (nt_comb(tokens, &index, value) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int	handle_no_value(char **value)
{
	*value = ft_strdup("");
	if (!*value)
		return (FAILURE);
	return (SUCCESS);
}
