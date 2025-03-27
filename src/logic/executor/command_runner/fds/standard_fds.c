/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:58:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/26 12:58:54 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_runner.h"

int	remember_standard_fds(int standard_fds[3])
{
	int	result;

	result = dup(STDIN_FILENO);
	if (result == -1)
		return (FAILURE);
	standard_fds[0] = result;
	result = dup(STDOUT_FILENO);
	if (result == -1)
		return (close(standard_fds[0]), FAILURE);
	standard_fds[1] = result;
	result = dup(STDERR_FILENO);
	if (result == -1)
		return (close(standard_fds[0]), close(standard_fds[1]), FAILURE);
	standard_fds[2] = result;
	return (SUCCESS);
}

int	restore_standard_fds(int standard_fds[3])
{
	int	result;

	result = redirect(STDIN_FILENO, standard_fds[0]);
	if (result == -1)
		return (FAILURE);
	result = redirect(STDOUT_FILENO, standard_fds[1]);
	if (result == -1)
		return (FAILURE);
	result = redirect(STDERR_FILENO, standard_fds[2]);
	if (result == -1)
		return (FAILURE);
	return (SUCCESS);
}

void	close_std_fd_copies(int fd_copies[3])
{
	close(fd_copies[0]);
	close(fd_copies[1]);
	close(fd_copies[2]);
}
