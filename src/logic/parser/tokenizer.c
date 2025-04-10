/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:25:15 by ismo              #+#    #+#             */
/*   Updated: 2025/04/10 14:26:08 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "token.h"
#include "ft_string.h"
#include "global_status_codes.h"
#include <stdlib.h>
#include "tokenizers.h"

int	tokenize(char *prompt, int *i, int is_variable, t_token *token)
{
	if (prompt[*i] && index_of(prompt[*i], "\"\'") != -1)
	{
		if (!tokenize_quote(token, prompt, i))
			return (false);
	}
	else if (prompt[*i] && index_of(prompt[*i], "<>") != -1)
		tokenize_redir(token, prompt, i);
	else if (prompt[*i] == '|')
		tokenize_one(token, i, Pipe);
	else if (is_variable && prompt[*i] == '=')
		tokenize_one(token, i, EqualSign);
	else if (prompt[*i] == '$')
		tokenize_env(token, prompt, i, is_variable);
	else if (prompt[*i] && !is_whitespace(prompt[*i]))
		tokenize_word(token, prompt, i, is_variable);
	else
		token->type = EndOfInput;
	return (true);
}

t_token	*get_next_token(char *prompt, int *i, int is_variable)
{
	t_token	*token;

	token = init_token();
	if (!token)
		return (NULL);
	while (prompt[*i] && is_whitespace(prompt[*i]))
		(*i)++;
	if (!tokenize(prompt, i, is_variable, token))
		return (free_token(token), NULL);
	if (token->type != EndOfInput)
		token->seperator = prompt[*i];
	else
		token->seperator = '\0';
	return (token);
}

t_list	*create_token_list(char *prompt, int is_variable)
{
	t_list	*tokens;
	t_token	*token;
	int		i;

	i = 0;
	token = get_next_token(prompt, &i, is_variable);
	if (!token)
		return (NULL);
	tokens = init_list();
	if (!tokens)
		return (NULL);
	while (token && token->type != EndOfInput)
	{
		add_to_list(tokens, token);
		token = get_next_token(prompt, &i, is_variable);
	}
	if (!token)
	{
		destroy_list(&tokens, free_token);
		return (NULL);
	}
	add_to_list(tokens, token);
	return (tokens);
}
