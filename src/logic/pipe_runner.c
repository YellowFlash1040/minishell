/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_runner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:16:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/20 18:27:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_runner.h"

int	run_a_pipe(t_pipe *pipe_v)
{
	int	result;
	int	pipe_fd[2];

	result = pipe(pipe_fd);
	if (result == -1)
		return (PIPE_FUNC_ERR);
	pipe_v->cmd1->output_file->fd = pipe_fd[WRITE_END];
	pipe_v->cmd1->unused_pipe_end = pipe_fd[READ_END];
	pipe_v->cmd2->input_file->fd = pipe_fd[READ_END];
	pipe_v->cmd2->unused_pipe_end = pipe_fd[WRITE_END];
	result = run_a_command(pipe_v->cmd1);
	if (result != SUCCESS)
		return (result);
	close(pipe_fd[WRITE_END]);
	result = run_a_command(pipe_v->cmd2);
	if (result != SUCCESS)
		return (result);
	close(pipe_fd[READ_END]);
	return (SUCCESS);
}
