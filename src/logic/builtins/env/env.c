/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:52:16 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/11 17:44:28 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	env(t_command *command)
{
	t_list			*env;
	t_string_array	exported_env;
	int				i;

	if (!command || !command->environment)
		return (FAILURE);
	env = command->environment;
	exported_env = construct_environment_for_export(env);
	if (!exported_env)
		return (FAILURE);
	i = -1;
	while (exported_env[++i])
		printf("%s\n", exported_env[i]);
	destroy_string_array(&exported_env);
	return (SUCCESS);
}
