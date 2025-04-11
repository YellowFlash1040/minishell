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

int	build_pipeline(t_pipeline **pipeline_ref)
{
	t_pipeline	*pipeline;

	if (!pipeline_ref)
		return (EMPTY_PIPELINE_REF_ERR);
	*pipeline_ref = init_pipeline();
	if (!*pipeline_ref)
		return (PIPELINE_INIT_ERR);
	pipeline = *pipeline_ref;
	pipeline->commands = init_list();
	if (!pipeline->commands)
		return (destroy_pipeline(pipeline_ref), COMMANDS_LIST_INIT_ERR);
	return (SUCCESS);
}
