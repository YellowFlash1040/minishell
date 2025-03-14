/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:51:54 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/09 14:58:24 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_string.h"
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>

typedef unsigned long	t_pointer;
typedef char			t_dtype;
typedef unsigned int	t_hex;

// -1 - nothing to add
// 0 - add space
// 1 - add +
typedef struct options
{
	bool	left_a; // left aligned
	bool	zero_flag;
	size_t	width;
	int		length;
	int		p_or_s; // plus or space: for the '+' ' ' flags
	bool	prefix; // for the '#' flag
	t_dtype	type;
}	t_options;

int		ft_printf(const char *s, ...);

int		print_arg(const char **s, va_list args);
int		print_string(char *str, size_t len);
int		print_number(long num);
int		print_unsigned(unsigned int num);
int		print_pointer(t_pointer p);
int		print_hex(t_hex num, char hex_case);

void	ft_printf_set_options(const char **s, t_options *opt);
int		print_char_bonus(va_list args, t_options *opt);
int		print_string_bonus(va_list args, t_options *opt);
int		print_number_bonus(va_list args, t_options *opt);
int		print_unsigned_bonus(va_list args, t_options *opt);
int		print_pointer_bonus(va_list args, t_options *opt);
int		print_hex_bonus(va_list args, t_options *opt);
int		print_char_n_times(char c, int count);

size_t	num_len(long long num, int base);
int		ft_printf_print_prefix(t_dtype type);
int		print_and_remove_sign(long *num, t_options *opt);

#endif