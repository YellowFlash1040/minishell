/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:47:23 by ismo              #+#    #+#             */
/*   Updated: 2025/04/10 16:55:39 by ibenne           ###   ########.fr       */
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

void	expand_token(t_list *env, t_token *token, t_list *list)
{
	if (token->type == SingleQuote || token->type == Word)
		add_to_list(list, ft_strdup(token->value));
	else if (token->type == DoubleQuote)
		add_to_list(list, expand_double_quote(env, token->value));
	else if (token->type == EnvVariable)
		add_to_list(list, dup_env_var(env, token->value));
}

char	*expand_comb(t_list *env, char *arg)
{
	char	*expanded_arg;
	t_list	*result;
	t_list	*tokens;
	int		t;
	t_token	*token;

	if (!arg || !env)
		return (NULL);
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
		expand_token(env, token, result);
		token = read_token(tokens, t++);
	}
	destroy_list(&tokens, free_token);
	expanded_arg = lst_to_str(&result);
	destroy_list(&result, free);
	return (expanded_arg);
}

void	expand_path(t_list *env, t_file *file)
{
	char	*expanded_path;

	expanded_path = expand_comb(env, file->path);
	if (expanded_path)
	{
		free(file->path);
		file->path = expanded_path;
	}
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
