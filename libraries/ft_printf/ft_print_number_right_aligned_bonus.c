/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_right_aligned_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:28:51 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_length(long *num, size_t num_l, size_t sign_len,
				t_options *opt);
static int	handle_zero(long *num, size_t biggest_size, t_options *opt);

int	print_right_aligned(long num, size_t num_l, size_t sign_len, t_options *opt)
{
	size_t	biggest_size;

	biggest_size = num_l + sign_len;
	if (opt->zero_flag)
		return (handle_zero(&num, biggest_size, opt));
	else if (opt->length != -1)
		return (handle_length(&num, num_l, sign_len, opt));
	if (opt->width > biggest_size)
	{
		if (print_char_n_times(' ', opt->width - biggest_size) == -1)
			return (-1);
		biggest_size = opt->width;
	}
	if (print_and_remove_sign(&num, opt) == -1
		|| print_unsigned(num) == -1)
		return (-1);
	return (biggest_size);
}

static int	handle_zero(long *num, size_t biggest_size, t_options *opt)
{
	if (print_and_remove_sign(num, opt) == -1)
		return (-1);
	if (opt->width > biggest_size)
	{
		if (print_char_n_times('0', opt->width - biggest_size) == -1)
			return (-1);
		biggest_size = opt->width;
	}
	if (print_unsigned(*num) == -1)
		return (-1);
	return (biggest_size);
}

static int	handle_length(long *num, size_t num_l, size_t sign_len,
		t_options *opt)
{
	size_t	biggest_size;

	biggest_size = num_l + sign_len;
	if (opt->length > (int)num_l)
		biggest_size = opt->length + sign_len;
	if (opt->length == 0 && *num == 0)
		biggest_size = 0;
	if (opt->width > biggest_size)
	{
		if (print_char_n_times(' ', opt->width - biggest_size) == -1)
			return (-1);
		biggest_size = opt->width;
	}
	if (!(opt->length == 0 && *num == 0))
	{
		if (print_and_remove_sign(num, opt) == -1)
			return (-1);
		if (opt->length > (int)num_l
			&& print_char_n_times('0', opt->length - num_l) == -1)
			return (-1);
		if (print_unsigned(*num) == -1)
			return (-1);
	}
	return (biggest_size);
}
