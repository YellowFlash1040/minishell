/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:01:26 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/16 18:07:50 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include "command.h"
# include "global_status_codes.h"
# include "error_printer.h"
# include <unistd.h>

int	cd(t_command *command);

#endif
