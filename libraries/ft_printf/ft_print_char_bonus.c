/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:00:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char_bonus(va_list args, t_options *opt)
{
	char	c;

	c = va_arg(args, int);
	if (opt->width)
	{
		if (opt->left_a)
		{
			if (write(1, &c, 1) == -1
				|| print_char_n_times(' ', opt->width - 1) == -1)
				return (-1);
		}
		else if (print_char_n_times(' ', opt->width - 1) == -1
			|| write(1, &c, 1) == -1)
			return (-1);
		return (opt->width);
	}
	return (write(1, &c, 1));
}
