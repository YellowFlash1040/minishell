/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:23:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/11 16:25:24 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

int			count_variables_for_export(t_list *env);
t_string	convert_variable_to_string(t_variable *variable);

t_variable	*create_variable(t_string env_var)
{
	t_variable		*var;
	t_string		parts[2];
	int				i;

	if (!env_var)
		return (NULL);
	i = 0;
	parts[0] = extract_word(env_var, &i, '=');
	if (!parts[0])
		return (NULL);
	i++;
	parts[1] = extract_word(env_var, &i, '\0');
	if (!parts[1])
		return (free(parts[0]), NULL);
	var = init_variable(parts[0], parts[1]);
	if (!var)
		return (free(parts[0]), free(parts[1]), NULL);
	var->is_exported = true;
	return (var);
}

void	free_variable(void *value)
{
	t_variable	*variable;

	variable = (t_variable *)value;
	destroy_variable(&variable);
}

t_string_array	construct_environment_for_export(t_list *env)
{
	t_string_array	export_env;
	t_list_node		*node;
	t_variable		*variable;
	int				i;

	if (!env)
		return (NULL);
	export_env = init_string_array(count_variables_for_export(env));
	if (!export_env)
		return (NULL);
	node = env->head;
	i = 0;
	while (node)
	{
		variable = (t_variable *)node->value;
		if (variable->is_exported)
		{
			export_env[i] = convert_variable_to_string(variable);
			if (!export_env[i])
				return (destroy_string_array(&export_env), NULL);
			i++;
		}
		node = node->next;
	}
	return (export_env);
}

int	count_variables_for_export(t_list *env)
{
	int			count;
	t_list_node	*node;
	t_variable	*variable;

	if (!env)
		return (-1);
	count = 0;
	node = env->head;
	while (node)
	{
		variable = (t_variable *)node->value;
		if (variable->is_exported)
			count++;
		node = node->next;
	}
	return (count);
}

t_string	convert_variable_to_string(t_variable *variable)
{
	t_string	temp;
	t_string	result;

	temp = ft_strjoin(variable->name, "=");
	if (!temp)
		return (NULL);
	result = temp;
	temp = ft_strjoin(result, variable->value);
	free(result);
	if (!temp)
		return (NULL);
	result = temp;
	return (result);
}
