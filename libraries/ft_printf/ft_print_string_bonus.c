/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:01:07 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str_and_empty_c(char *s, size_t str_pcc, t_options *opt);

int	print_string_bonus(va_list args, t_options *opt)
{
	char	*str;
	size_t	str_len;
	size_t	str_pcc;

	str = va_arg(args, char *);
	str_len = ft_strlen(str);
	if (!str && (opt->length == -1 || opt->length >= 6))
		str_len = 6;
	str_pcc = str_len;
	if (opt->length != -1 && opt->length < (int)str_len)
		str_pcc = opt->length;
	if (opt->width > str_pcc)
		return (print_str_and_empty_c(str, str_pcc, opt));
	if (print_string(str, str_pcc) == -1)
		return (-1);
	return (str_pcc);
}

static int	print_str_and_empty_c(char *s, size_t str_pcc, t_options *opt)
{
	if (opt->left_a)
	{
		if (print_string(s, str_pcc) == -1)
			return (-1);
		if (print_char_n_times(' ', opt->width - str_pcc) == -1)
			return (-1);
		return (opt->width);
	}
	if (print_char_n_times(' ', opt->width - str_pcc) == -1)
		return (-1);
	if (print_string(s, str_pcc) == -1)
		return (-1);
	return (opt->width);
}
