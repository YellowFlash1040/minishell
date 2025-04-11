/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_unset_env_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:50:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/11 13:49:47 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

bool	compare_variables_by_name(void *value1, void *value2);
void	free_variable(void *value);
int		add_env_variable(t_list *env, t_string name, t_string value,
			bool is_exported);

int	set_env_variable(t_list *env, t_string name, t_string value,
	bool is_exported)
{
	t_list_node	*node;
	t_variable	*variable;
	t_string	name_copy;

	node = find_node(name, env, compare_variables_by_name);
	if (node)
	{
		variable = (t_variable *)node->value;
		variable->is_exported = is_exported;
		if (value != NULL)
		{
			free(variable->value);
			variable->value = value;
		}
		return (SUCCESS);
	}
	else
	{
		name_copy = ft_strdup(name);
		if (!name_copy)
			return (FAILURE);
		return (add_env_variable(env, name_copy, value, is_exported));
	}
}

int	add_env_variable(t_list *env, t_string name, t_string value,
	bool is_exported)
{
	t_variable	*variable;

	variable = init_variable(name, value);
	if (!variable)
		return (FAILURE);
	variable->is_exported = is_exported;
	if (!add_to_list(env, variable))
		return (destroy_variable(&variable), FAILURE);
	return (SUCCESS);
}

int	unset_env_variable(t_list *env, t_string name)
{
	if (remove_from_list(name, env, compare_variables_by_name, free_variable))
		return (SUCCESS);
	return (FAILURE);
}

bool	compare_variables_by_name(void *value1, void *value2)
{
	t_variable	*variable;
	t_string	name;

	if (!value1 || !value2)
		return (false);
	variable = (t_variable *)value1;
	name = (t_string)value2;
	return (ft_strcmp(variable->name, name));
}

t_string	get_env_variable(t_list *env, t_string name)
{
	t_list_node	*node;
	t_variable	*variable;

	node = find_node(name, env, compare_variables_by_name);
	if (!node)
		return (NULL);
	variable = (t_variable *)node->value;
	if (!variable)
		return (NULL);
	return (variable->value);
}
