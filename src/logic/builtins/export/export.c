/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:02:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/30 15:27:49 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	split_argument_into_parts(t_string argument, t_string parts[2]);

int	export(t_command *command)
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
		result = set_env_variable(env, parts[0], parts[1], true);
		free(parts[0]);
		if (result != SUCCESS)
			return (free(parts[1]), result);
		i++;
	}
	return (SUCCESS);
}

int	split_argument_into_parts(t_string argument, t_string parts[2])
{
	int	i;

	parts[0] = NULL;
	parts[1] = NULL;
	if (index_of('=', argument) != -1)
	{
		i = 0;
		parts[0] = extract_word(argument, &i, '=');
		if (!parts[0])
			return (FAILURE);
		i++;
		parts[1] = extract_word(argument, &i, '\0');
		if (!parts[1])
		{
			free(parts[0]);
			parts[0] = NULL;
			return (FAILURE);
		}
		return (SUCCESS);
	}
	parts[0] = ft_strdup(argument);
	if (!parts[0])
		return (FAILURE);
	return (SUCCESS);
}
