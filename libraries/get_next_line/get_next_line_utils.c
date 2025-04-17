/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:16:33 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 14:05:11 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer_size(int fd, ssize_t *rb_c)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*rb_c = read(fd, buffer, BUFFER_SIZE);
	if (*rb_c == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[*rb_c] = '\0';
	return (buffer);
}

char	*extractn(char *s, size_t n)
{
	char	*res;
	size_t	len;

	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	len = n;
	res[n] = '\0';
	while (len--)
	{
		res[len] = s[len];
		s[len] = '\0';
	}
	while (s[n])
	{
		s[++len] = s[n];
		s[n++] = '\0';
	}
	return (res);
}

char	*join(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	res_i;

	if (!s1)
		return (s2);
	else if (!s2)
		return (s1);
	res = (char *)malloc(sizeof(char) * (len(s1) + len(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	res_i = 0;
	while (s1[i])
		res[res_i++] = s1[i++];
	i = 0;
	while (s2[i])
		res[res_i++] = s2[i++];
	res[res_i] = '\0';
	free(s1);
	free(s2);
	return (res);
}

size_t	len(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
