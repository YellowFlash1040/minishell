/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:25:09 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/15 13:09:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_runner.h"

int	setup_command_io(t_command *command);
int	launch_binary(t_string name, t_string_array args);
int	setup_binary_path(t_string *name_ref);
int	print_not_found_err(t_string binary_path);

int	execute_external(t_command *command)
{
	int	result;

	result = setup_command_io(command);
	if (result != SUCCESS)
		return (result);
	return (launch_binary(command->executable, command->arguments));
}

int	launch_binary(t_string name, t_string_array args)
{
	int	result;

	setup_binary_path(&name);
	result = execve(name, args, NULL);
	if (result == -1)
	{
		if (errno == ENOENT)
		{
			result = print_not_found_err(name);
			if (result != SUCCESS)
				return (result);
			return (FAILURE);
		}
		return (perror("Error"), BINARY_LAUNCH_ERR);
	}
	return (SUCCESS);
}

int	setup_binary_path(t_string *name_ref)
{
	t_string	name;
	t_string	binary_path;
	int			result;

	name = *name_ref;
	result = find_binary(name, &binary_path);
	if (result != SUCCESS)
		return (result);
	if (binary_path != NULL)
	{
		free(name);
		*name_ref = binary_path;
	}
	return (SUCCESS);
}

int	print_not_found_err(t_string binary_path)
{
	t_string	message;
	int			result;

	message = ft_strjoin(binary_path, ": command not found\n");
	if (!message)
		return (perror("Error"), MALLOC_FAIL_ERR);
	result = print_error_message(message);
	free(message);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}
