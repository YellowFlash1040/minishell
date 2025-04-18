/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:47:23 by ismo              #+#    #+#             */
/*   Updated: 2025/04/18 17:40:46 by ibenne           ###   ########.fr       */
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
#include "expander_utils.h"

bool	expand_token(t_list *env, t_token *token, t_list *list)
{
	char	*expanded_tok;

	expanded_tok = NULL;
	if (token->type == SingleQuote || token->type == Word)
		expanded_tok = ft_strdup(token->value);
	else if (token->type == DoubleQuote)
		expanded_tok = expand_double_quote(env, token->value);
	else if (token->type == EnvVariable)
		expanded_tok = dup_env_var(env, token->value);
	if (!expanded_tok || !add_to_list(list, expanded_tok))
		return (free(expanded_tok), false);
	return (true);
}

char	*expand_comb(t_list *env, char *arg)
{
	char	*expanded_arg;
	t_list	*result;
	t_list	*tokens;
	int		t;
	t_token	*token;

	tokens = create_token_list(arg, 0);
	if (!tokens)
		return (NULL);
	result = init_list();
	if (!result)
		return (destroy_list(&tokens, free_token), NULL);
	t = 0;
	token = read_token(tokens, t++);
	while (token && is_file(token->type))
	{
		if (!expand_token(env, token, result))
			return (destroy_list(&tokens, free_token),
				destroy_list(&result, free), free_token(token), NULL);
		token = read_token(tokens, t++);
	}
	destroy_list(&tokens, free_token);
	expanded_arg = lst_to_str(&result);
	destroy_list(&result, free);
	return (expanded_arg);
}

int	expand_path(t_list *env, t_file *file)
{
	char	*expanded_path;

	expanded_path = expand_comb(env, file->path);
	if (!expanded_path)
		return (FAILURE);
	free(file->path);
	file->path = expanded_path;
	return (SUCCESS);
}

int	expand_arguments(t_command *command)
{
	int			i;
	char		*tmp_str;

	i = 0;
	while (command->arguments[i])
	{
		tmp_str = expand_comb(command->environment, command->arguments[i]);
		if (tmp_str)
		{
			free(command->arguments[i]);
			command->arguments[i] = tmp_str;
		}
		else
			return (FAILURE);
		if (!command->executable && i == 0)
			command->executable = ft_strdup(command->arguments[i]);
		if (!command->executable)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
