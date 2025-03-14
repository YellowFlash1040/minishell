/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:01:10 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(const char **s, va_list args)
{
	t_options	opt;

	ft_printf_set_options(s, &opt);
	if (opt.type == 'c')
		return (print_char_bonus(args, &opt));
	else if (opt.type == 's')
		return (print_string_bonus(args, &opt));
	else if (opt.type == 'p')
		return (print_pointer_bonus(args, &opt));
	else if (opt.type == 'd' || opt.type == 'i')
		return (print_number_bonus(args, &opt));
	else if (opt.type == 'u')
		return (print_unsigned_bonus(args, &opt));
	else if (opt.type == 'x' || opt.type == 'X')
		return (print_hex_bonus(args, &opt));
	else if (opt.type == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	print_char_n_times(char c, int count)
{
	int	count_copy;

	if (count <= 0)
		return (0);
	count_copy = count;
	while (count--)
	{
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	return (count_copy);
}
