/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:23:10 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/14 14:51:06 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_PRINTER_H
# define ERROR_PRINTER_H

# include "ft_string.h"
# include "global_status_codes.h"
# include <unistd.h>
# include <stdio.h>

int	print_error_message(t_string message);

#endif
