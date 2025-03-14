/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:50:28 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_left_aligned(t_hex num, size_t num_l, t_options *opt,
				size_t prefix_len);
static int	print_right_aligned(t_hex num, size_t num_l, t_options *opt,
				size_t prefix_len);
static int	handle_zero(t_hex num, size_t num_l, t_options *opt,
				size_t prefix_len);
static int	handle_length(t_hex num, size_t num_l, t_options *opt,
				size_t prefix_len);

int	print_hex_bonus(va_list args, t_options *opt)
{
	t_hex	num;
	size_t	num_l;
	size_t	prefix_len;

	num = va_arg(args, t_hex);
	num_l = num_len(num, 16);
	prefix_len = 0;
	if (opt->prefix && num != 0)
		prefix_len = 2;
	if (opt->left_a)
		return (print_left_aligned(num, num_l, opt, prefix_len));
	return (print_right_aligned(num, num_l, opt, prefix_len));
}

static int	print_left_aligned(t_hex num, size_t num_l, t_options *opt,
		size_t prefix_len)
{
	size_t	biggest_size;

	biggest_size = num_l;
	if (opt->length == 0 && num == 0)
		biggest_size = 0;
	if (prefix_len != 0 && biggest_size != 0)
		if (ft_printf_print_prefix(opt->type) == -1)
			return (-1);
	if (opt->length > (int)num_l)
	{
		if (print_char_n_times('0', opt->length - num_l) == -1)
			return (-1);
		biggest_size = opt->length;
	}
	if (biggest_size != 0 && print_hex(num, opt->type) == -1)
		return (-1);
	biggest_size += prefix_len;
	if (opt->width > biggest_size)
	{
		if (print_char_n_times(' ', opt->width - biggest_size) == -1)
			return (-1);
		biggest_size = opt->width;
	}
	return (biggest_size);
}

static int	print_right_aligned(t_hex num, size_t num_l, t_options *opt,
		size_t prefix_len)
{
	size_t	biggest_size;

	if (opt->zero_flag)
		return (handle_zero(num, num_l, opt, prefix_len));
	if (opt->length != -1)
		return (handle_length(num, num_l, opt, prefix_len));
	biggest_size = num_l + prefix_len;
	if (opt->width > biggest_size)
	{
		if (print_char_n_times(' ', opt->width - biggest_size) == -1)
			return (-1);
		biggest_size = opt->width;
	}
	if (prefix_len != 0 && ft_printf_print_prefix(opt->type) == -1)
		return (-1);
	if (print_hex(num, opt->type) == -1)
		return (-1);
	return (biggest_size);
}

static int	handle_length(t_hex num, size_t num_l, t_options *opt,
		size_t prefix_len)
{
	size_t	biggest_size;

	biggest_size = num_l;
	if (opt->length > (int)num_l || (opt->length == 0 && num == 0))
		biggest_size = opt->length;
	biggest_size += prefix_len;
	if (opt->width > biggest_size)
	{
		if (print_char_n_times(' ', opt->width - biggest_size) == -1)
			return (-1);
		biggest_size = opt->width;
	}
	if (!(opt->length == 0 && num == 0))
	{
		if (prefix_len != 0 && ft_printf_print_prefix(opt->type) == -1)
			return (-1);
		if (opt->length > (int)num_l)
			if (print_char_n_times('0', opt->length - num_l) == -1)
				return (-1);
		if (print_hex(num, opt->type) == -1)
			return (-1);
	}
	return (biggest_size);
}

static int	handle_zero(t_hex num, size_t num_l, t_options *opt,
		size_t prefix_len)
{
	size_t	count;

	count = 0;
	if (prefix_len && ft_printf_print_prefix(opt->type) == -1)
		return (-1);
	count += prefix_len;
	if (opt->width > num_l + prefix_len)
	{
		opt->width -= num_l + prefix_len;
		if (print_char_n_times('0', opt->width) == -1)
			return (-1);
		count += opt->width;
	}
	if (print_hex(num, opt->type) == -1)
		return (-1);
	count += num_l;
	return (count);
}
