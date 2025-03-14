/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_left_aligned_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:03:11 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_length_and_width(long *num, int num_l, size_t sign_len,
				t_options *opt);
static int	handle_width(long *num, int num_l, size_t sign_len, t_options *opt);

int	print_left_aligned(long num, size_t num_l, size_t sign_len, t_options *opt)
{
	if (opt->length != -1)
		return (handle_length_and_width(&num, num_l, sign_len, opt));
	else if (opt->width > num_l + sign_len)
		return (handle_width(&num, num_l, sign_len, opt));
	if (print_and_remove_sign(&num, opt) == -1
		|| print_unsigned(num) == -1)
		return (-1);
	return (num_l + sign_len);
}

static int	handle_width(long *num, int num_l, size_t sign_len, t_options *opt)
{
	if (print_and_remove_sign(num, opt) == -1
		|| print_unsigned(*num) == -1
		|| print_char_n_times(' ', opt->width - (num_l + sign_len)) == -1)
		return (-1);
	return (opt->width);
}

static int	handle_length_and_width(long *num, int num_l, size_t sign_len,
		t_options *opt)
{
	size_t	biggest_size;

	biggest_size = num_l + sign_len;
	if (opt->length == 0 && *num == 0)
		biggest_size = 0;
	if (biggest_size != 0)
	{
		if (print_and_remove_sign(num, opt) == -1
			|| print_char_n_times('0', opt->length - num_l) == -1
			|| print_unsigned(*num) == -1)
			return (-1);
		if (opt->length > num_l)
			biggest_size = opt->length + sign_len;
	}
	if (opt->width > biggest_size)
	{
		if (print_char_n_times(' ', opt->width - biggest_size) == -1)
			return (-1);
		biggest_size = opt->width;
	}
	return (biggest_size);
}
