/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:04:41 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/19 12:39:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

int	pwd(t_command *command)
{
	t_string	wd;

	if (!command || !command->environment)
		return (FAILURE);
	wd = get_env_variable(command->environment, "PWD");
	if (!wd)
		return (FAILURE);
	write(STDOUT_FILENO, wd, ft_strlen(wd));
	write(STDOUT_FILENO, "\n", 1);
	return (SUCCESS);
}
