/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:57:38 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 16:38:03 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_processor.h"

bool	check_file(t_file *file);

int	process_file(t_file *file)
{
	int	result;

	if (!check_file(file))
		return (FILE_ACCESS_ERR);
	result = open_file(file);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

bool	check_file(t_file *file)
{
	if (file->mode == READ && access(file->path, R_OK) != 0)
	{
		if (access(file->path, F_OK) != 0)
		{
			print_error_message(file->path);
			print_error_message(": No such file or directory\n");
			return (false);
		}
		else
		{
			print_error_message(file->path);
			print_error_message(": Permission denied\n");
			return (false);
		}
	}
	else if (access(file->path, W_OK) != 0)
	{
		if (access(file->path, F_OK) != 0)
			return (true);
		print_error_message(file->path);
		print_error_message(": Permission denied\n");
		return (false);
	}
	return (true);
}
