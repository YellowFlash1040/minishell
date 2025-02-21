/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_runner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:16:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/20 14:07:37 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_RUNNER_H
# define PIPE_RUNNER_H

# include "command_runner.h"
# include "pipe.h"

# define PIPE_FUNC_ERR 180

int	run_a_pipe(t_pipe *pipe);

#endif
