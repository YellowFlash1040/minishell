/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:08:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/19 15:14:57 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_builtin.h"

int	count_arguments(t_string_array args)
{
	int	i;

	i = 0;
	while (args && args[i])
		i++;
	return (i);
}

int	exit_builtin(t_command *command)
{
	int	exit_status;

	if (count_arguments(command->arguments) > 2)
		return (print_error_message("exit: too many arguments\n"),
			FAILURE);
	exit_status = SUCCESS;
	if (command->arguments[1])
		exit_status = ft_atoi(command->arguments[1]);
	exit(exit_status);
}
