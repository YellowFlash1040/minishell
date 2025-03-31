/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibenne <ibenne@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/12 16:07:18 by ismo          #+#    #+#                 */
/*   Updated: 2025/03/29 19:28:15 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
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

	token = read_token(tokens, index++);
	n = 0;
	while (token && token->type != EndOfInput && (is_file(token) || is_redir(token)))
	{
		if (is_redir(token))
		{
			index++;
			token = read_token(tokens, index++);
		}
		else
		{
			n++;
			while (token && token->type != EndOfInput && is_file(token) && !is_whitespace(token->seperator))
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
	else if (token->type == DoubleQuote)
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
