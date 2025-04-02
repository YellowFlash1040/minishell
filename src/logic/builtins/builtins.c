/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:04:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/02 15:24:01 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	is_builtin(t_string binary_name)
{
	const t_string	builtins[] = {"echo", "cd",
		"pwd", "export", "unset", "env", "exit", "set", NULL};
	int				i;

	i = -1;
	while (builtins[++i])
		if (ft_strcmp(binary_name, builtins[i]))
			return (true);
	return (false);
}

int	launch_builtin(t_command *command)
{
	const t_string	names[] = {"echo", "cd",
		"pwd", "export", "unset", "env", "exit", "set", NULL};
	const t_builtin	builtins[] = {echo, cd,
		pwd, export, unset, env, exit_builtin, set};
	int				i;

	i = -1;
	while (names[++i])
		if (ft_strcmp(command->executable, names[i]))
			return (builtins[i](command));
	return (FAILURE);
}
