/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:12:20 by akovtune          #+#    #+#             */
/*   Updated: 2024/10/18 14:03:02 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_p;
	const unsigned char	*src_p;

	if (src == dest)
		return (dest);
	dest_p = dest;
	src_p = src;
	if (src_p > dest_p)
		while (n--)
			*dest_p++ = *src_p++;
	else
	{
		src_p += n - 1;
		dest_p += n - 1;
		while (n--)
			*dest_p-- = *src_p--;
	}
	return (dest);
}
