/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/26 12:38:15 by ismo          #+#    #+#                 */
/*   Updated: 2025/03/26 12:59:07 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "environment.h"
#include "command.h"

char	*lst_to_str(t_list *list)
{
	int			n;
	int			i;
	int			j;
	t_list_node	*node;
	char		*res;

	n = 0;
	j = 0;
	while ((node = get_node(n++, list)))
		j += ft_strlen((char *) node->value);
	res = (char *)malloc(j + 1);
	if (!res)
		return (NULL);
	n = 0;
	i = 0;
	while ((node = get_node(n++, list)))
	{
		j = 0;
		while (((char *)node->value)[j])
			res[i++] = ((char *)node->value)[j++];
	}
	res[i] = '\0';
	return (res);
}

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
	tmp_str = lst_to_str(result);
	destroy_list(&result, free);
	return (tmp_str);
}

void	expand_command(t_command *command)
{
	int		arg;
	char	*tmp_str;

	arg = 0;
	while (command->arguments[arg])
	{
		if (command->parsable[arg])
		{
			tmp_str = expand_str(command->environment, command->arguments[arg]);
			if (!tmp_str)
				continue ;
			free(command->arguments[arg]);
			command->arguments[arg] = tmp_str;
		}
		if (arg == 0)
			command->executable = ft_strdup(command->arguments[arg]);
		arg++;
	}
	if (command->is_redir_parsable)
	{
		// expand redir
	}

}
