/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_runner.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:34:16 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/19 18:55:29 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_RUNNER_H
# define COMMAND_RUNNER_H

# include "command.h"

# define CHILD_PROCESS pid == 0

int	run_a_command(t_command *command);

#endif