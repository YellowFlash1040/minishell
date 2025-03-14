/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:00:58 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_opt_minus_and_revert(long *num);
static size_t	get_power(long num);

int	print_number(long num)
{
	int	count;
	int	fcc;

	count = print_opt_minus_and_revert(&num);
	if (count == -1)
		return (-1);
	fcc = print_unsigned(num);
	if (fcc == -1)
		return (-1);
	return (count + fcc);
}

int	print_unsigned(unsigned int num)
{
	int		power;
	char	digit;
	int		count;
	char	digit_character;

	count = 0;
	power = get_power(num);
	while (power)
	{
		digit = num / power;
		digit_character = '0' + digit;
		if (write(1, &digit_character, 1) == -1)
			return (-1);
		count++;
		num -= digit * power;
		power /= 10;
	}
	return (count);
}

int	print_hex(t_hex num, char hex_case)
{
	int		offset;
	char	c;
	int		started;
	char	a;

	a = 'A';
	if (hex_case == 'x')
		a = 'a';
	started = 0;
	offset = sizeof(num) * 2;
	while (offset-- > 0)
	{
		c = (num >> offset * 4) & 0xF;
		if (c > 9)
			c = a + (c - 10);
		else
			c = '0' + c;
		if (c > '0' || started || offset == 0)
		{
			if (write(1, &c, 1) == -1)
				return (-1);
			started++;
		}
	}
	return (started);
}

static int	print_opt_minus_and_revert(long *num)
{
	if (*num >= 0)
		return (0);
	if (write(1, "-", 1) == -1)
		return (-1);
	*num = -*num;
	return (1);
}

static size_t	get_power(long num)
{
	size_t	p;

	p = 1;
	num /= 10;
	while (num)
	{
		p *= 10;
		num /= 10;
	}
	return (p);
}
