/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_controller.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:31:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/13 19:34:23 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_CONTROLLER_H
# define PIPES_CONTROLLER_H

# include "list.h"
# include "p1pe.h"
# include "global_status_codes.h"

int	create_all_pipes(t_list *pipes, int amount);
int	close_all_pipes(t_list *pipes);

#endif