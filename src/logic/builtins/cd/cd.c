/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:01:31 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/19 12:22:56 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

bool		has_more_than_2_args(t_command *command);
t_string	get_new_directory(t_list *env, t_string_array args);
t_string	get_current_directory(t_list *env);
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
	new_oldpwd = get_current_directory(command->environment);
	if (!new_oldpwd)
		return (FAILURE);
	new_dir = get_new_directory(command->environment, command->arguments);
	if (!new_dir)
		return (FAILURE);
	if (chdir(new_dir) == -1)
		return (perror("cd"), FAILURE);
	result = update_env_variables(command->environment, new_oldpwd);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

t_string	get_new_directory(t_list *env, t_string_array args)
{
	if (args[1] != NULL)
	{
		if (ft_strcmp(args[1], "-"))
			return (get_env_variable(env, "OLDPWD"));
		return (args[1]);
	}
	return (get_env_variable(env, "HOME"));
}

t_string	get_current_directory(t_list *env)
{
	t_string	current_dir;

	current_dir = get_env_variable(env, "PWD");
	if (!current_dir)
		return (NULL);
	return (current_dir);
}

int	update_env_variables(t_list *env, t_string new_oldpwd)
{
	int	result;
	t_string oldpwd;

	oldpwd = ft_strdup(new_oldpwd);
	if (!oldpwd)
		return (FAILURE);
	result = set_env_variable(env, "OLDPWD", oldpwd, true);
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
