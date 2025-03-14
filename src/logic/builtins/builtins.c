/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:04:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/13 15:12:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	is_builtin(t_string binary_name)
{
	const t_string	builtins[] = {"echo", "cd",
		"pwd", "export", "unset", "env", "exit", NULL};
	int				i;

	i = -1;
	while (builtins[++i])
		if (ft_strcmp(binary_name, builtins[i]))
			return (true);
	return (false);
}

int	launch_builtin(t_string name, t_string_array args)
{
	const t_string	names[] = {"echo", "cd",
		"pwd", "export", "unset", "env", "exit", NULL};
	const t_builtin	builtins[] = {echo, cd};
	int				i;

	i = -1;
	while (names[++i])
		if (ft_strcmp(name, names[i]))
			return (builtins[i](args));
	return (FAILURE);
}
