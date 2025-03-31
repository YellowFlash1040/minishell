/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:04:41 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/29 17:59:02 by akovtune         ###   ########.fr       */
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
	printf("%s\n", wd);
	free(wd);
	return (SUCCESS);
}
