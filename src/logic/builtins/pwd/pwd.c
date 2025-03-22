/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:04:41 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/22 18:29:28 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

int	pwd(t_command *command)
{
	t_string	wd;

	if (!command || !command->environment)
		return (FAILURE);
	wd = getcwd(NULL, 0);
	if (!wd)
		return (FAILURE);
	write(STDOUT_FILENO, wd, ft_strlen(wd));
	write(STDOUT_FILENO, "\n", 1);
	free(wd);
	return (SUCCESS);
}
