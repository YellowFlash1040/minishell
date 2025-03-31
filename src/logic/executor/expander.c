/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/26 12:38:15 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/01 00:20:14 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "ft_string.h"
#include "variable.h"
#include "environment.h"
#include "command.h"
#include "lst_to_str.h"
#include "token.h"
#include "tokenizer.h"
#include "parser_utils.h"

char	*expand_str(t_list *env, char	*str)
{
	t_list			*result;
	char			*var_name;
	char			*tmp_str;
	int				i;

	result = init_list();
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			var_name = extract_word2(str, &i, " $");
			if (!var_name)
			{
				tmp_str = ft_strdup("$");
				if (!tmp_str)
					return (NULL);
			}
			else
			{
				tmp_str = get_env_variable(env, var_name);
				if (!tmp_str)
					tmp_str = ft_strdup(" ");
				if (!tmp_str)
					return (NULL);
				tmp_str = ft_strdup(tmp_str);
			}
			add_to_list(result, tmp_str);
		}
		else
		{
			tmp_str = extract_word2(str, &i, "$");
			if (!tmp_str)
				break  ;
			add_to_list(result, tmp_str);
		}
	}
	tmp_str = lst_to_str(&result);
	destroy_list(&result, free);
	return (tmp_str);
}

void	expand_variable(t_list *env, t_variable *variable)
{
	char	*tmp_str;

	// check if parsable
	if (true)
	{
		tmp_str = expand_str(env, variable->value);
		free(variable->value);
		variable->value = tmp_str;
	}
}

char	*dup_env_var(t_list *env, char *name)
{
	char	*value;

	value = get_env_variable(env, name);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}

char	*expand_comb(t_list *env, char *arg)
{
	char	*expanded_arg;
	t_list 	*result;
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
		return (NULL);
	t = 0;
	token = read_token(tokens, t++);
	while (token && token->type != EndOfInput)
	{
		if (token->type == SingleQuote || token->type == Word)
			add_to_list(result, ft_strdup(token->value));
		else if (token->type == DoubleQuote)
			add_to_list(result, expand_str(env, token->value));
		else if (token->type == EnvVariable)
			add_to_list(result, dup_env_var(env, token->value));
		token = read_token(tokens, t++);
	}
	destroy_list(&tokens, free_token);
	expanded_arg = lst_to_str(&result);
	destroy_list(&result, free);
	return (expanded_arg);
}

void	expand_file(t_list *env, t_file *file)
{
	char *expanded_path;

	expanded_path = expand_comb(env, file->path);
	if (expanded_path)
	{
		free(file->path);
		file->path = expanded_path;
	}
}

int	expand_command(t_command *command)
{
	int			i;
	char		*tmp_str;
	t_list_node	*int_node;

	i = 0;
	while (command->arguments[i])
	{
		tmp_str = expand_comb(command->environment, command->arguments[i]);
		if (tmp_str)
		{
			free(command->arguments[i]);
			command->arguments[i] = tmp_str;
		}
		if (i == 0)
			command->executable = ft_strdup(command->arguments[i]);
		i++;
	}
	i = 0;
	int_node = get_node(i++, command->intermediate_files);
	while (int_node && int_node->value)
	{
		expand_file(command->environment, int_node->value);
		int_node = get_node(i++, command->intermediate_files);
	}
	if (command->input_file && command->input_file->fd != STDIN_FILENO)
		expand_file(command->environment, command->input_file);
	if (command->output_file && command->output_file->fd != STDOUT_FILENO)
		expand_file(command->environment, command->output_file);
	return (SUCCESS);
}

void	expand_commands(t_list **commands)
{
	int	i;
	t_list_node	*node;

	i = 0;
	node = get_node(i, *commands);
	while (node)
	{
		expand_command((t_command *)node->value);
		node = get_node(++i, *commands);
	}
}
