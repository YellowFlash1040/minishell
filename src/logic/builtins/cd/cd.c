/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:01:31 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/18 15:23:04 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

bool		has_more_than_2_args(t_command *command);
t_string	get_new_directory(t_list *env, t_string_array args);
int			change_directory(t_string new_dir, t_command *command);
int			update_env_variables(t_list *env, t_string new_oldpwd);

int	cd(t_command *command)
{
	t_string		new_dir;
	t_string		new_oldpwd;
	int				result;

	if (!command || !command->arguments)
		return (FAILURE);
	if (has_more_than_2_args(command))
		return (print_error_message("cd: too many arguments\n"), SUCCESS);
	new_oldpwd = getcwd(NULL, 0);
	if (!new_oldpwd)
		return (FAILURE);
	new_dir = get_new_directory(command->environment, command->arguments);
	if (!new_dir)
		return (free(new_oldpwd), FAILURE);
	result = change_directory(new_dir, command);
	if (result != SUCCESS)
		return (free(new_oldpwd), result);
	result = update_env_variables(command->environment, new_oldpwd);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

int	change_directory(t_string new_dir, t_command *command)
{
	int	result;

	result = chdir(new_dir);
	if (result == -1)
	{
		if (errno == ENOENT)
		{
			command->exit_status_code = FAILURE;
			if (index_of('~', new_dir) != -1)
				print_error_message("cd: we don't support '~' expansion\n");
			else
			{
				print_error_message("cd: ");
				print_no_such_file_err(new_dir);
			}
			return (SUCCESS);
		}
		return (perror("cd"), FAILURE);
	}
	return (SUCCESS);
}

int	update_env_variables(t_list *env, t_string new_oldpwd)
{
	int			result;
	t_string	new_pwd;

	result = set_env_variable(env, "OLDPWD", new_oldpwd, true);
	if (result != SUCCESS)
		return (result);
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		return (FAILURE);
	result = set_env_variable(env, "PWD", new_pwd, true);
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
