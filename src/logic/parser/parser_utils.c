/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/12 16:07:18 by ismo          #+#    #+#                 */
/*   Updated: 2025/03/13 14:16:53 by ismo          ########   odam.nl         */
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

int is_redir(t_token *token)
{
	return (token && (token->type == RedirAppend || token->type == RedirDelim || token->type == RedirInput || token->type == RedirOutput));
}

int	n_word_tokens(t_list *tokens, int index)
{
	t_token *token;
	int		n;

	token = read_token(tokens, index);
	n = 0;
	while (token && token->type == Word)
	{
		token = read_token(tokens, index++);
		n++;
	}
	return (n);
}
