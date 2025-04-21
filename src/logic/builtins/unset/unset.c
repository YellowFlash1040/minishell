/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:45:53 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/16 17:50:22 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

int	unset(t_command *command)
{
	t_list			*env;
	t_string_array	args;
	int				result;
	int				i;

	if (!command || !command->arguments || !command->environment)
		return (FAILURE);
	args = command->arguments;
	env = command->environment;
	i = 1;
	while (args[i])
	{
		result = unset_env_variable(env, args[i]);
		if (result != SUCCESS)
			return (result);
		i++;
	}
	return (SUCCESS);
}
