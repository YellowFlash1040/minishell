/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:04:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/12 13:15:17 by akovtune         ###   ########.fr       */
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
