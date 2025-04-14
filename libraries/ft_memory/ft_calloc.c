/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:30:31 by akovtune          #+#    #+#             */
/*   Updated: 2024/10/15 19:23:52 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	int		bytes_count;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > INT_MAX / size)
		return (NULL);
	bytes_count = nmemb * size;
	p = (char *)malloc(bytes_count);
	if (!p)
		return (NULL);
	while (bytes_count--)
		*p++ = '\0';
	return (p - nmemb * size);
}
