/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:31:15 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_left_aligned(long num, size_t num_l, size_t sign_len,
			t_options *opt);
int		print_right_aligned(long num, size_t num_l, size_t sign_len,
			t_options *opt);

int	print_number_bonus(va_list args, t_options *opt)
{
	long	num;
	size_t	num_l;
	size_t	sign_len;

	num = va_arg(args, int);
	num_l = num_len(num, 10);
	sign_len = 0;
	if ((num < 0 || opt->p_or_s != -1))
		sign_len = 1;
	if (opt->left_a)
		return (print_left_aligned(num, num_l, sign_len, opt));
	return (print_right_aligned(num, num_l, sign_len, opt));
}

// utils for printing d, i, x, X -----------------------------------------------

size_t	num_len(long long num, int base)
{
	size_t	len;

	len = 1;
	if (num < 0)
		num = -num;
	while (num / base > 0)
	{
		len++;
		num /= base;
	}
	return (len);
}

int	print_and_remove_sign(long *num, t_options *opt)
{
	if (*num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		*num = -*num;
		return (1);
	}
	else if (opt->p_or_s != -1)
	{
		if (opt->p_or_s == 1 && write(1, "+", 1) == -1)
			return (-1);
		else if (opt->p_or_s == 0 && write(1, " ", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

int	ft_printf_print_prefix(t_dtype type)
{
	if (type == 'x')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
	}
	else if (write(1, "0X", 2) == -1)
		return (-1);
	return (2);
}
