/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p1pe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:15:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/18 15:14:36 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p1pe.h"

t_p1pe	*init_p1pe(void)
{
	t_p1pe	*p1pe;
	int		pipe_fd[2];
	int		result;

	result = pipe(pipe_fd);
	if (result == -1)
		return (perror("pipe"), NULL);
	p1pe = (t_p1pe *)malloc(sizeof(t_p1pe));
	if (!p1pe)
	{
		close(pipe_fd[READ_END]);
		close(pipe_fd[WRITE_END]);
		return (NULL);
	}
	p1pe->read_end = pipe_fd[READ_END];
	p1pe->write_end = pipe_fd[WRITE_END];
	return (p1pe);
}

void	destroy_p1pe(t_p1pe **p1pe_ref)
{
	t_p1pe	*p1pe;

	if (!p1pe_ref || !*p1pe_ref)
		return ;
	p1pe = *p1pe_ref;
	close(p1pe->read_end);
	close(p1pe->write_end);
	free(p1pe);
	*p1pe_ref = NULL;
}
