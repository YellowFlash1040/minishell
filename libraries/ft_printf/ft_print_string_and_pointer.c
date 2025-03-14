/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_and_pointer.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:01:04 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str, size_t len)
{
	size_t	str_len;

	if (len == 0)
		return (0);
	if (!str)
		return (write(1, "(null)", 6));
	str_len = ft_strlen(str);
	if (len > str_len)
		len = str_len;
	return (write(1, str, len));
}

int	print_pointer(t_pointer p)
{
	int		offset;
	char	c;
	int		started;

	if (!p)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	started = 0;
	offset = sizeof(p) * 2;
	while (offset-- > 0)
	{
		c = (p >> offset * 4) & 0xF;
		if (c > 9)
			c = 'a' + (c - 10);
		else
			c = '0' + c;
		if (started || c > '0')
		{
			if (write(1, &c, 1) == -1)
				return (-1);
			started++;
		}
	}
	return (started + 2);
}
