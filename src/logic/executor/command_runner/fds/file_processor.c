/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:57:38 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/10 17:41:18 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_processor.h"

bool		check_file(t_file *file);
bool		check_input_file(t_file *file);
bool		check_output_file(t_file *file);
t_string	extract_directory(t_string path);

int	process_file(t_file *file)
{
	int	result;

	if (ft_strcmp(file->path, ""))
	{
		print_no_such_file_err(file->path);
		return (EMPTY_FILE_PATH_ERR);
	}
	if (!check_file(file))
		return (FILE_ACCESS_ERR);
	result = open_file(file);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

bool	check_file(t_file *file)
{
	if (file->mode == READ)
		return (check_input_file(file));
	return (check_output_file(file));
}

bool	check_input_file(t_file *file)
{
	if (access(file->path, R_OK) == 0)
		return (true);
	if (access(file->path, F_OK) == 0)
	{
		print_permission_denied_err(file->path);
		return (false);
	}
	print_no_such_file_err(file->path);
	return (false);
}

bool	check_output_file(t_file *file)
{
	t_string	file_directory;

	if (access(file->path, W_OK) == 0)
		return (true);
	if (access(file->path, F_OK) == 0)
	{
		print_permission_denied_err(file->path);
		return (false);
	}
	if (!string_contains(file->path, "/"))
		return (true);
	file_directory = extract_directory(file->path);
	if (access(file_directory, F_OK) == 0)
		return (destroy_string(&file_directory), true);
	destroy_string(&file_directory);
	print_no_such_file_err(file->path);
	return (false);
}

t_string	extract_directory(t_string path)
{
	t_string	result;
	int			path_str_length;
	int			file_name_length;

	if (index_of('/', path) == -1)
		return (NULL);
	path_str_length = ft_strlen(path);
	file_name_length = path_str_length - last_index_of('/', path);
	result = ft_substr(path, 0, path_str_length - file_name_length);
	if (!result)
		return (NULL);
	return (result);
}
