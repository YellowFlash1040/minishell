/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:41:44 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/11 20:04:04 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

int			count_variables_for_export(t_list *env);
t_string	convert_variable_to_string(t_variable *variable);
t_variable	*create_variable(t_string env_var);
void		free_variable(void *value);

t_list	*init_environment(char *envp[])
{
	t_list		*environment;
	t_string	variable;
	int			i;

	if (!envp)
		return (NULL);
	environment = init_list();
	if (!environment)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		variable = create_variable(envp[i]);
		if (!variable)
			return (clear_list(environment, free_variable), NULL);
		if (!add_to_list(environment, variable))
			return (destroy_variable(variable),
				clear_list(environment, free_variable), NULL);
	}
	return (environment);
}

t_variable	*create_variable(t_string env_var)
{
	t_variable		*var;
	t_string_array	parts;

	if (!env_var)
		return (NULL);
	parts = ft_split(env_var, '=');
	if (!parts)
		return (NULL);
	var = init_variable(parts[0]);
	if (!var)
		return (destroy_string_array(parts), NULL);
	var->value = parts[1];
	var->string_value = env_var;
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
				return (destroy_string_array(export_env), NULL);
		}
		node = node->next;
		i++;
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
