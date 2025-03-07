/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:37:36 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/09 14:07:09 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	index_of(char c, char *str)
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

int	last_index_of(char c, char *str)
{
	int	i;
	int	last_index;

	if (!str)
		return (-1);
	last_index = -1;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			last_index = i;
	return (last_index);
}

bool	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] && s2[i])
		if (s1[i] != s2[i])
			return (false);
	if (!(s1[i] == '\0' && s2[i] == '\0'))
		return (false);
	return (true);
}

char	*ft_strdup(char *str)
{
	char	*copy;
	int		i;

	if (!str)
		return (NULL);
	copy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (str[++i])
		copy[i] = str[i];
	copy[i] = '\0';
	return (copy);
}
