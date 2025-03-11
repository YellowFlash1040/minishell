/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:33:21 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/11 20:02:40 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable.h"

t_variable	*init_variable(t_string name)
{
	t_variable	*variable;

	variable = (t_variable *)malloc(sizeof(t_variable));
	if (!variable)
		return (NULL);
	variable->name = name;
	variable->value = NULL;
	variable->is_exported = false;
	return (variable);
}

void	destroy_variable(t_variable **variable_ref)
{
	t_variable	*variable;

	if (!variable_ref || !*variable_ref)
		return ;
	variable = *variable_ref;
	if (variable->name)
		free(variable->name);
	if (variable->value)
		free(variable->value);
	free(variable);
	*variable_ref = NULL;
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
	if (!temp)
		return (free(result), NULL);
	result = temp;
	return (result);
}
