/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibenne <ibenne@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/12 16:07:18 by ismo          #+#    #+#                 */
/*   Updated: 2025/03/24 16:26:08 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "list.h"

t_token *read_token(t_list *tokens, int index)
{
	t_list_node *node;

	node = get_node(index, tokens);
	if (index >= tokens->count)
		return (NULL);
	return ((t_token*) node->value);
}

int	is_file(t_token *token)
{
	return (token && (token->type == Word || token->type == EnvVariable || token->type == DoubleQuote || token->type == SingleQuote));
}

int is_redir(t_token *token)
{
	return (token && (token->type == RedirAppend || token->type == RedirDelim || token->type == RedirInput || token->type == RedirOutput));
}

int	n_args(t_list *tokens, int index)
{
	t_token *token;
	int		n;

	token = read_token(tokens, index);
	n = 0;
	while (token && is_file(token) && is_redir(token))
	{
		if (is_redir(token))
			index += 2;
		token = read_token(tokens, index++);
		n++;
	}
	return (n);
}
