/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:13:16 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 16:15:31 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stream.h"

t_stream	*init_stream(void)
{
	t_stream	*stream;

	stream = (t_stream *)malloc(sizeof(t_stream));
	if (!stream)
		return (NULL);
	stream->fd = -1;
	stream->type = UNDEFINED_STREAM;
	return (stream);
}

void	destroy_stream(t_stream **stream_ref)
{
	t_stream	*stream;

	if (!stream_ref || !*stream_ref)
		return ;
	stream = *stream_ref;
	free(stream);
	*stream_ref = NULL;
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
