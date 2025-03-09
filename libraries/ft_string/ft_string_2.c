/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:35:08 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/09 17:04:41 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	replace(char *str, char old, char new)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == old)
			str[i] = new;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_length;
	int		s2_length;
	char	*res;
	int		i;
	int		index;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (s1_length + s2_length + 1));
	if (!res)
		return (NULL);
	i = -1;
	index = 0;
	while (s1 && s1[++i] != '\0')
		res[index++] = s1[i];
	i = -1;
	while (s2 && s2[++i] != '\0')
		res[index++] = s2[i];
	res[index] = '\0';
	return (res);
}
