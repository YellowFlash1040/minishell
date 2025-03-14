/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:01:01 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_ptr_len(t_pointer p);

int	print_pointer_bonus(va_list args, t_options *opt)
{
	t_pointer	p;
	size_t		length;

	p = (t_pointer)va_arg(args, void *);
	length = get_ptr_len(p);
	if (p == (t_pointer) NULL)
		length = 5;
	if (opt->width > length)
	{
		if (opt->left_a && print_pointer(p) == -1)
			return (-1);
		print_char_n_times(' ', opt->width - length);
		if (!opt->left_a && print_pointer(p) == -1)
			return (-1);
		return (opt->width);
	}
	if (print_pointer(p) == -1)
		return (-1);
	return (length);
}

static size_t	get_ptr_len(t_pointer p)
{
	int		offset;
	int		num;
	size_t	length;

	offset = sizeof(void *) * 2;
	length = offset + 2;
	while (offset--)
	{
		num = (p >> 4 * offset) & 0xF;
		if (num > 0)
			return (length);
		length--;
	}
	return ((size_t) NULL);
}
