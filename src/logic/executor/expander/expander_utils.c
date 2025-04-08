/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:33:48 by ismo              #+#    #+#             */
/*   Updated: 2025/04/08 16:59:12 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "lst_to_str.h"
#include "environment.h"
#include "ft_string.h"
#include "tokenizer_utils.h"

char	*dup_env_var(t_list *env, char *name)
{
	char	*value;

	if (!name || ft_strlen(name) <= 0)
		value = ft_strdup("$");
	else
	{
		value = get_env_variable(env, name);
		if (!value)
			return (ft_strdup(""));
		else
			value = ft_strdup(value);
	}
	if (!value)
		return (NULL);
	return (value);
}

char	*expand_double_quote_var(t_list *env, char *str, int *i)
{
	char			*var_name;
	char			*tmp_str;

	(*i)++;
	var_name = scan_word(str, i, "$", true);
	tmp_str = dup_env_var(env, var_name);
	free(var_name);
	return (tmp_str);
}

char	*expand_double_quote(t_list *env, char	*str)
{
	t_list			*result;
	char			*tmp_str;
	int				i;

	result = init_list();
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			tmp_str = expand_double_quote_var(env, str, &i);
		else
			tmp_str = scan_word(str, &i, "$", false);
		if (!tmp_str)
			return (destroy_list(&result, free), NULL);
		add_to_list(result, tmp_str);
	}
	tmp_str = lst_to_str(&result);
	return (destroy_list(&result, free), tmp_str);
}
