/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_printer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:03:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/21 18:19:57 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PRINTER_H
# define CLASS_PRINTER_H

# include "command.h"
# include <stdio.h>

void	print_a_command(t_command *command, char *tabs);
void	print_a_file(t_file *file, char *tabs);
void	print_a_string_array(char **arr, char *tabs);

#endif
