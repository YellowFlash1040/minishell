/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:24:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/22 16:24:54 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

bool	compare_variables_by_name(void *value1, void *value2);
void	free_variable(void *value);

int	unset_env_variable(t_list *env, t_string name)
{
	if (remove_from_list(name, env, compare_variables_by_name, free_variable))
		return (SUCCESS);
	return (FAILURE);
}
