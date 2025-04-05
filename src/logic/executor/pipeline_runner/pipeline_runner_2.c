/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_runner_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:19:59 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/04 15:01:36 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipeline_runner.h"

bool	close_pipes(int prev_pipe[2], int current_pipe[2])
{
	if (prev_pipe[READ_END] != STDIN_FILENO)
		close(prev_pipe[READ_END]);
	if (current_pipe[READ_END] != -1)
		close(current_pipe[READ_END]);
	if (current_pipe[WRITE_END] != STDOUT_FILENO)
		close(current_pipe[WRITE_END]);
	return (true);
}

//if a command fails
//then if it received it's input from a pipe, 
//which you can check by
//prev_pipe[READ_END] != STDIN (means the input was from a pipe)
//- close it
//and close both ends of the pipe to the next command (if there is one)
//which you can check by
//current_pipe[READ_END] = -1
//current_pipe[WRITE_END] = STDOUT_FILENO
//since we don't need it