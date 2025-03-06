/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:42:07 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/20 14:17:43 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_builder.h"

int	build_pipe(t_pipe **pipe)
{
	t_pipe	*pipe_v;
	int		result;

	if (!pipe)
		return (EMPTY_PIPE_REF_ERR);
	*pipe = init_pipe();
	if (!*pipe)
		return (PIPE_INIT_ERR);
	pipe_v = *pipe;
	result = build_command(&pipe_v->cmd1);
	if (result != SUCCESS)
		return (COMMAND_BUILDER_ERR);
	result = build_command(&pipe_v->cmd2);
	if (result != SUCCESS)
		return (COMMAND_BUILDER_ERR);
	return (SUCCESS);
}
