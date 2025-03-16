/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:07:20 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/16 18:20:14 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_BUILTIN_H
# define EXIT_BUILTIN_H

# include "command.h"
# include "converter.h"
# include "error_printer.h"

int	exit_builtin(t_command *command);

#endif