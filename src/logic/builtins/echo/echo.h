/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:57:04 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/16 16:28:33 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H

# include "string_array.h"
# include "global_status_codes.h"
# include "command.h"
# include <unistd.h>

int	echo(t_command *command);

#endif