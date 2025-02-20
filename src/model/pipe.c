/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:52:07 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/20 13:16:10 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

t_pipe	*init_pipe(void)
{
	t_pipe	*pipe;

	pipe = (t_pipe *)malloc(sizeof(t_pipe));
	if (!pipe)
		return (NULL);
	pipe->cmd1 = NULL;
	pipe->cmd2 = NULL;
	return (pipe);
}

void	destroy_pipe(t_pipe **pipe)
{
	if (!pipe || !*pipe)
		return ;
	free(*pipe);
	*pipe = NULL;
}

/*
TODO: maybe I'll have to make some changes in the destructor later on
*/