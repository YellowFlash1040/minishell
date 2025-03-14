/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:56:23 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_left_aligned(unsigned int num, size_t num_l, t_options *opt);
static int	print_right_aligned(unsigned int num, size_t num_l, t_options *opt);
static int	handle_length_and_width(unsigned int num, size_t num_l,
				t_options *opt, size_t biggest_size);

int	print_unsigned_bonus(va_list args, t_options *opt)
{
	unsigned int	num;
	size_t			num_l;

	num = va_arg(args, unsigned int);
	num_l = num_len(num, 10);
	if (opt->left_a)
		return (print_left_aligned(num, num_l, opt));
	return (print_right_aligned(num, num_l, opt));
}

static int	print_left_aligned(unsigned int num, size_t num_l, t_options *opt)
{
	size_t	biggest_size;

	biggest_size = num_l;
	if (opt->length == 0 && num == 0)
		biggest_size = 0;
	if (opt->length > (int)num_l)
	{
		if (print_char_n_times('0', opt->length - num_l) == -1)
			return (-1);
		biggest_size = opt->length;
	}
	if (biggest_size != 0 && print_unsigned(num) == -1)
		return (-1);
	if (opt->width > biggest_size)
	{
		if (print_char_n_times(' ', opt->width - biggest_size) == -1)
			return (-1);
		biggest_size = opt->width;
	}
	return (biggest_size);
}

static int	print_right_aligned(unsigned int num, size_t num_l, t_options *opt)
{
	size_t	biggest_size;

	biggest_size = num_l;
	if (opt->zero_flag)
	{
		if (opt->width > num_l)
		{
			if (print_char_n_times('0', opt->width - num_l) == -1)
				return (-1);
			biggest_size = opt->width;
		}
		if (print_unsigned(num) == -1)
			return (-1);
		return (biggest_size);
	}
	return (handle_length_and_width(num, num_l, opt, biggest_size));
}

static int	handle_length_and_width(unsigned int num, size_t num_l,
		t_options *opt, size_t biggest_size)
{
	if (opt->length == 0 && num == 0)
		biggest_size = 0;
	if (opt->length > (int)num_l)
		biggest_size = opt->length;
	if (opt->width > biggest_size)
	{
		if (print_char_n_times(' ', opt->width - biggest_size) == -1)
			return (-1);
		biggest_size = opt->width;
	}
	if (!(opt->length == 0 && num == 0))
	{
		if (opt->length > (int)num_l)
		{
			if (print_char_n_times('0', opt->length - num_l) == -1)
				return (-1);
		}
		if (print_unsigned(num) == -1)
			return (-1);
	}
	return (biggest_size);
}
