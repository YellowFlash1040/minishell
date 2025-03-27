/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:52:14 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/21 14:33:47 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

t_file	*init_file(void)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->fd = -1;
	file->path = NULL;
	file->mode = NONE;
	return (file);
}

void	destroy_file(t_file **file_ref)
{
	t_file	*file;

	if (!file_ref || !*file_ref)
		return ;
	file = *file_ref;
	if (file->path)
		free(file->path);
	free(file);
	*file_ref = NULL;
}

int	redirect(int old_fd, int new_fd)
{
	int	result;
	int	duplicated_fd;
	int	redirected_fd;

	duplicated_fd = new_fd;
	redirected_fd = old_fd;
	result = dup2(duplicated_fd, redirected_fd);
	if (result == -1)
		return (perror("dup2 error"), FD_DUP_ERR);
	close(duplicated_fd);
	return (SUCCESS);
}

int	open_file(t_file *file)
{
	if (!file || !file->path)
		return (EMPTY_FILE_REF_OR_PATH_ERR);
	if (file->mode == NONE)
		return (EMPTY_FILE_MODE_ERR);
	file->fd = open(file->path, file->mode, 0777);
	if (file->fd == -1)
		return (FILE_OPEN_ERR);
	return (SUCCESS);
}
