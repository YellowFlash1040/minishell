/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:07:18 by ismo              #+#    #+#             */
/*   Updated: 2025/04/18 16:28:56 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "token.h"
#include "list.h"

t_token	*read_token(t_list *tokens, int index)
{
	t_list_node	*node;

	node = get_node(index, tokens);
	if (!node || index >= tokens->count)
		return (NULL);
	return ((t_token *) node->value);
}

int	is_file(t_token_type type)
{
	return (type == Word
		|| type == EnvVariable
		|| type == DoubleQuote
		|| type == SingleQuote);
}

int	is_redir(t_token_type type)
{
	return (type == RedirAppend
		|| type == RedirDelim
		|| type == RedirInput
		|| type == RedirOutput);
}

int	n_args(t_list *tokens, int index)
{
	t_token	*token;
	int		n;

	token = read_token(tokens, index++);
	n = 0;
	while (token && token->type != EndOfInput
		&& (is_file(token->type) || is_redir(token->type)))
	{
		if (is_redir(token->type))
		{
			index++;
			token = read_token(tokens, index++);
		}
		else
		{
			n++;
			while (token && token->type != EndOfInput
				&& is_file(token->type) && !is_whitespace(token->seperator))
				token = read_token(tokens, index++);
			token = read_token(tokens, index++);
		}
	}
	return (n);
}

char	*quote_str(t_token *token)
{
	char	*quoted_str;
	char	quote;
	int		i;

	quoted_str = (char *)malloc(ft_strlen(token->value) + 3);
	if (!quoted_str)
		return (NULL);
	if (token->type == SingleQuote)
		quote = '\'';
	else
		quote = '"';
	quoted_str[0] = quote;
	i = 0;
	while (token->value[i])
	{
		quoted_str[i + 1] = token->value[i];
		i++;
	}
	quoted_str[i + 1] = quote;
	quoted_str[i + 2] = '\0';
	return (quoted_str);
}
