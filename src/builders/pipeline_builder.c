/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:07:58 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/14 16:00:14 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipeline_builder.h"

int	build_pipeline(t_pipeline **pipeline)
{
	t_pipeline	*pipeline_v;

	if (!pipeline)
		return (EMPTY_PIPELINE_REF_ERR);
	*pipeline = init_pipeline();
	if (!*pipeline)
		return (PIPELINE_INIT_ERR);
	pipeline_v = *pipeline;
	pipeline_v->commands = init_list();
	if (!pipeline_v->commands)
		return (destroy_pipeline(pipeline), COMMANDS_LIST_INIT_ERR);
	return (SUCCESS);
}
