/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:01:31 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/16 16:29:24 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

int	count_arguments(t_string_array args);

//TODO: handle `cd -` command

int	cd(t_command *command)
{
	t_string_array	args;
	int				args_count;
	int				result;

	if (!command || !command->arguments)
		return (FAILURE);
	args = command->arguments;
	args_count = count_arguments(args);
	if (args_count < 2)
		return (SUCCESS);
	if (args_count > 2)
		return (print_error_message("cd: too many arguments\n"),
			FAILURE);
	result = chdir(args[1]);
	if (result == -1)
		return (perror("Error"), FAILURE);
	return (SUCCESS);
}

int	count_arguments(t_string_array args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}
