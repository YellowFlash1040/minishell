/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_runner.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:40:19 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/21 14:55:58 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_RUNNER_H
# define PIPELINE_RUNNER_H

# include "pipeline.h"
# include "command_runner.h"

# define PIPE_FUNC_ERR 200

typedef enum e_pipe_end
{
	READ_END = 0,
	WRITE_END = 1
}				t_pipe_end;

int	run_a_pipeline(t_pipeline *pipeline);

#endif
