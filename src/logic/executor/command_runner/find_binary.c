/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:41:12 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/16 15:36:59 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_runner.h"

int	check_using_abs_rel_path(t_string path, t_string *result);
int	check_using_env_path(t_string path, t_string *result);
int	search_binary_in_folders(t_string binary, t_string_array folders,
		t_string *result);

int	find_binary(t_string path, t_string *result)
{
	*result = NULL;
	if (!path)
		return (FAILURE);
	if (path[0] == '\0')
		return (SUCCESS);
	if (index_of('/', path) != -1)
		return (check_using_abs_rel_path(path, result));
	return (check_using_env_path(path, result));
}

int	check_using_abs_rel_path(t_string path, t_string *result)
{
	t_string	temp;

	*result = NULL;
	if (access(path, F_OK) == 0)
	{
		temp = ft_strdup(path);
		if (!temp)
			return (FAILURE);
		*result = temp;
	}
	return (SUCCESS);
}

int	check_using_env_path(t_string path, t_string *result)
{
	t_string		env_path;
	t_string_array	folders;
	int				status_code;

	*result = NULL;
	env_path = getenv("PATH");
	if (!env_path)
		return (0);
	folders = ft_split(env_path, ':');
	if (!folders)
		return (FAILURE);
	status_code = search_binary_in_folders(path, folders, result);
	destroy_string_array(&folders);
	if (status_code != SUCCESS)
		return (status_code);
	return (SUCCESS);
}

int	search_binary_in_folders(t_string binary, t_string_array folders,
		t_string *result)
{
	int			i;
	t_string	slash_binary;
	t_string	full_path;

	*result = NULL;
	slash_binary = ft_strjoin("/", binary);
	if (!slash_binary)
		return (FAILURE);
	i = -1;
	while (folders[++i])
	{
		if (folders[i][ft_strlen(folders[i]) - 1] == '/')
			full_path = ft_strjoin(folders[i], binary);
		else
			full_path = ft_strjoin(folders[i], slash_binary);
		if (!full_path)
			return (free(slash_binary), FAILURE);
		if (access(full_path, F_OK) == 0)
		{
			*result = full_path;
			return (free(slash_binary), SUCCESS);
		}
		free(full_path);
	}
	return (free(slash_binary), SUCCESS);
}
