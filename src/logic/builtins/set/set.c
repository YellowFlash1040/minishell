/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:34:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/16 17:48:16 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int	split_argument_into_parts(t_string argument, t_string parts[2]);

int	set(t_command *command)
{
	t_list			*env;
	t_string_array	args;
	t_string		parts[2];
	int				result;
	int				i;

	if (!command || !command->arguments || !command->environment)
		return (FAILURE);
	args = command->arguments;
	env = command->environment;
	i = 1;
	while (args[i])
	{
		result = split_argument_into_parts(args[i], parts);
		if (result != SUCCESS)
			return (result);
		result = set_env_variable(env, parts[0], parts[1], false);
		if (result != SUCCESS)
			return (free(parts[0]), free(parts[1]), result);
		i++;
	}
	return (SUCCESS);
}
