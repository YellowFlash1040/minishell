/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:11:42 by ismo              #+#    #+#             */
/*   Updated: 2025/04/02 15:42:50 by ibenne           ###   ########.fr       */
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
	if (!token || token->type != EqualSign)
		return (FAILURE);
	while (token->type == EqualSign)
		token = read_token(tokens, ++index);
	if (!token || nt_comb(tokens, &index, value) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int	parse_pipeline(t_list *tokens, t_pipeline **pipeline, t_list *env)
{
	int	index;

	index = 0;
	if (nt_pipeline(tokens, &index, pipeline, env) == SUCCESS)
		return (SUCCESS);
	return (FAILURE);
}
