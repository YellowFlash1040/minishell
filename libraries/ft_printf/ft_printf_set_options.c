/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_options.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:00:52 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initialize_options(t_options *opt);
static void	adjust_options(t_options *opt);
static int	ft_isdigit(int c);

void	ft_printf_set_options(const char **s, t_options *opt)
{
	initialize_options(opt);
	while (*++(*s) && index_of(**s, "cspdiuxX%") == -1)
	{
		if (**s == '-')
			opt->left_a = true;
		else if (**s == '0' && !opt->width && opt->length == -1)
			opt->zero_flag = true;
		else if (**s == '+')
			opt->p_or_s = 1;
		else if (**s == ' ' && opt->p_or_s != 1)
			opt->p_or_s = 0;
		else if (**s == '#')
			opt->prefix = true;
		else if (**s == '.')
			opt->length = 0;
		else if (ft_isdigit(**s) && opt->length != -1)
			opt->length = opt->length * 10 + **s - '0';
		else if (ft_isdigit(**s))
			opt->width = opt->width * 10 + **s - '0';
	}
	if (**s)
	{
		opt->type = *(*s)++;
		adjust_options(opt);
	}
}

static void	adjust_options(t_options *opt)
{
	char	t;

	t = opt->type;
	if (index_of(t, "di") == -1)
		opt->p_or_s = -1;
	if (index_of(t, "diuxXs") == -1)
		opt->length = -1;
	if (index_of(t, "xX") == -1)
		opt->prefix = false;
	if (opt->left_a || opt->length != -1 || index_of(t, "diuxX") == -1)
		opt->zero_flag = false;
}

static void	initialize_options(t_options *opt)
{
	opt->left_a = false;
	opt->zero_flag = false;
	opt->p_or_s = -1;
	opt->prefix = false;
	opt->width = 0;
	opt->length = -1;
	opt->type = '\0';
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
