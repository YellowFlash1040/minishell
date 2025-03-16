/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:41:44 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/16 17:08:38 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

t_variable	*create_variable(t_string env_var);
void		free_variable(void *value);

t_list	*init_environment(char *envp[])
{
	t_list		*environment;
	t_variable	*variable;
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
			return (destroy_environment(&environment), NULL);
		if (!add_to_list(environment, variable))
			return (destroy_variable(&variable),
				destroy_environment(&environment), NULL);
	}
	return (environment);
}

void	destroy_environment(t_list **environment_ref)
{
	if (!environment_ref)
		return ;
	destroy_list(environment_ref, free_variable);
}
