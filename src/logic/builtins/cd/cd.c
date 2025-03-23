/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:01:31 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/23 14:21:52 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

bool		has_more_than_2_args(t_command *command);
t_string	get_new_directory(t_list *env, t_string_array args);
int			update_env_variables(t_list *env, t_string new_oldpwd);

int	cd(t_command *command)
{
	t_string		new_dir;
	t_string		new_oldpwd;
	int				result;

	if (!command || !command->arguments)
		return (FAILURE);
	if (has_more_than_2_args(command))
	{
		print_error_message("cd: too many arguments\n");
		return (SUCCESS);
	}
	new_oldpwd = getcwd(NULL, 0);
	if (!new_oldpwd)
		return (FAILURE);
	new_dir = get_new_directory(command->environment, command->arguments);
	if (!new_dir)
		return (free(new_oldpwd), FAILURE);
	if (chdir(new_dir) == -1)
		return (perror("cd"), FAILURE);
	result = update_env_variables(command->environment, new_oldpwd);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

t_string	get_new_directory(t_list *env, t_string_array args)
{
	t_string	new_directory;

	if (args[1] == NULL || ft_strcmp(args[1], ""))
		return (get_env_variable(env, "HOME"));
	if (ft_strcmp(args[1], "-"))
	{
		new_directory = get_env_variable(env, "OLDPWD");
		if (!new_directory)
		{
			print_error_message("cd: OLDPWD not set\n");
			return (NULL);
		}
		return (new_directory);
	}
	return (args[1]);
}

int	update_env_variables(t_list *env, t_string new_oldpwd)
{
	int			result;

	result = set_env_variable(env, "OLDPWD", new_oldpwd, true);
	if (result != SUCCESS)
		return (result);
	result = set_env_variable(env, "PWD", getcwd(NULL, 0), true);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

bool	has_more_than_2_args(t_command *command)
{
	int	i;

	i = 0;
	while (command->arguments[i])
		i++;
	if (i > 2)
	{
		command->exit_status_code = FAILURE;
		return (true);
	}
	return (false);
}
