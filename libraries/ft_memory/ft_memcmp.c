/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:32:04 by akovtune          #+#    #+#             */
/*   Updated: 2024/10/18 13:53:29 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = s1;
	p2 = s2;
	i = -1;
	while (++i < n && p1[i] == p2[i])
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
	if (i != n)
		return (p1[i] - p2[i]);
	return (0);
}
