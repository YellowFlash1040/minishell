/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:25:09 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/05 17:04:44 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_runner.h"

int	setup_command_io(t_command *command);
int	launch_binary(t_string name, t_string_array args, t_list *env);
int	setup_binary_path(t_string *name_ref, t_list *env);
int	find_binary(t_string path, t_list *env, t_string *result);
int	print_not_found_err(t_string binary_path);

int	execute_external(t_command *command)
{
	int	result;

	result = setup_command_io(command);
	if (result != SUCCESS || command->exit_status_code != SUCCESS)
		return (result);
	result = launch_binary(command->executable, command->arguments,
			command->environment);
	if (result != SUCCESS)
	{
		if (result == 127)
		{
			command->exit_status_code = 127;
			result = SUCCESS;
		}
		return (result);
	}
	return (SUCCESS);
}

int	launch_binary(t_string name, t_string_array args, t_list *env)
{
	int				result;
	t_string_array	environment;

	setup_binary_path(&name, env);
	environment = construct_environment_for_export(env);
	if (!environment)
		return (FAILURE);
	result = execve(name, args, environment);
	if (result == -1)
	{
		destroy_string_array(&environment);
		if (errno == ENOENT)
		{
			if (ft_strcmp(name, ""))
				result = print_not_found_err("''");
			else
				result = print_not_found_err(name);
			if (result != SUCCESS)
				return (result);
			return (127);
		}
		return (perror("Error"), BINARY_LAUNCH_ERR);
	}
	return (SUCCESS);
}

int	setup_binary_path(t_string *name_ref, t_list *env)
{
	t_string	name;
	t_string	binary_path;
	int			result;

	name = *name_ref;
	result = find_binary(name, env, &binary_path);
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
		return (perror("Error"), FAILURE);
	result = print_error_message(message);
	free(message);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}
