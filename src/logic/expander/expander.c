/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:38:15 by ismo              #+#    #+#             */
/*   Updated: 2025/04/18 16:53:24 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "ft_string.h"
#include "variable.h"
#include "environment.h"
#include "command.h"
#include "lst_to_str.h"
#include "token.h"
#include "tokenizer_utils.h"
#include "tokenizer.h"
#include "parser_utils.h"
#include "expanders.h"
#include "expander_utils.h"

int	expand_command(t_command *command)
{
	t_list_node		*redir_node;
	t_redirection	*redir;

	if (expand_arguments(command) != SUCCESS)
		return (FAILURE);
	redir_node = command->redirections->head;
	while (redir_node && redir_node->value)
	{
		redir = (t_redirection *) redir_node->value;
		if (redir->target->type == FILE_TYPE
			&& expand_path(command->environment, redir->target->value)
			!= SUCCESS)
			return (FAILURE);
		redir_node = redir_node->next;
	}
	return (SUCCESS);
}

int	expand_commands(t_list **commands)
{
	t_list_node	*node;

	node = (*commands)->head;
	while (node)
	{
		if (expand_command((t_command *)node->value) != SUCCESS)
			return (FAILURE);
		node = node->next;
	}
	return (SUCCESS);
}
