/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:01:13 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		fcc;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s != '%')
			fcc = write(1, s++, 1);
		else
			fcc = print_arg(&s, args);
		if (fcc == -1)
			return (-1);
		count += fcc;
	}
	va_end(args);
	return (count);
}

/*
Format Structure:
The general structure of a format specifier in printf is:

%[flags][width][.precision][length]type

%: Indicates the start of the format specifier.
[flags]: Optional flags (like -, 0, +, #, space).
[width]: Optional minimum width of the output.
[.precision]: Optional precision specification
[length]: Optional length modifier
type: Required type specifier (like d, s, c, etc.)
— this must always be the last part.


-----------------------------------------------
Flag	Description	Compatible Formats
-	Left-align the output	d, i, u, x, X, s, c, p
+	Force sign display for numbers	d, i
0	Zero-pad the output	d, i, u, x, X
#	(0x or 0X prefix)	x, X
Space for positive numbers	d, i

width - d, i, u, x, X, s, c, p. this is the minimum output width

length - d, i, u, x, X, s
*/

//First working bonus version