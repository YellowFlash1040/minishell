/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:52:46 by akovtune          #+#    #+#             */
/*   Updated: 2024/10/18 13:52:55 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_p;
	const unsigned char	*src_p;

	if (dest == src)
		return (dest);
	dest_p = dest;
	src_p = src;
	while (n--)
		*dest_p++ = *src_p++;
	return (dest);
}
