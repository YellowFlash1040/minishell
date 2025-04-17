/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:22:16 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 14:14:16 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_from_leftover(char **leftover, t_gnl gnl);
static int	index_of(char c, char *str);
static void	free_and_null(char **pointer);

char	*get_next_line(int fd)
{
	static char	*leftover;
	t_gnl		gnl;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (free_and_null(&leftover), NULL);
	gnl.buffer = read_buffer_size(fd, &gnl.rb_c);
	if (!gnl.buffer)
		return (free_and_null(&leftover), NULL);
	while (gnl.rb_c > 0)
	{
		gnl.temp = join(leftover, gnl.buffer);
		if (!gnl.temp)
			return (free(gnl.buffer), free_and_null(&leftover), NULL);
		leftover = gnl.temp;
		gnl.nl_index = index_of('\n', leftover);
		if (gnl.nl_index != -1)
			return (extract_from_leftover(&leftover, gnl));
		gnl.buffer = read_buffer_size(fd, &gnl.rb_c);
		if (!gnl.buffer)
			return (free_and_null(&leftover), NULL);
	}
	free(gnl.buffer);
	return (extract_from_leftover(&leftover, gnl));
}

static char	*extract_from_leftover(char **leftover, t_gnl gnl)
{
	gnl.nl_index = index_of('\n', *leftover);
	if (gnl.nl_index == -1)
		gnl.nl_index = len(*leftover) - 1;
	gnl.temp = extractn(*leftover, gnl.nl_index + 1);
	if ((*leftover && (*leftover)[0] == '\0') || !gnl.temp)
		free_and_null(leftover);
	return (gnl.temp);
}

static int	index_of(char c, char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

static void	free_and_null(char **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
	}
}
