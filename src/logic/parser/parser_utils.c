/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:07:18 by ismo              #+#    #+#             */
/*   Updated: 2025/03/21 18:08:31 by ibenne           ###   ########.fr       */
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

char	*escape_env(char *str)
{
	int		i;
	int		len;
	char 	*escaped_str;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$')
			len += 2;
		else
			len++;
		i++;
	}
	escaped_str = (char *)malloc(len + 1);
	if (!escaped_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (escaped_str);
}
