/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:05:53 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/21 17:57:32 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipeline.h"

void		free_command(void *value);

t_pipeline	*init_pipeline(void)
{
	t_pipeline	*pipeline;

	pipeline = (t_pipeline *)malloc(sizeof(t_pipeline));
	if (!pipeline)
		return (NULL);
	pipeline->commands = NULL;
	pipeline->status_code = 0;
	return (pipeline);
}

void	destroy_pipeline(t_pipeline **pipeline)
{
	t_pipeline	*pipeline_v;

	if (!pipeline || !*pipeline)
		return ;
	pipeline_v = *pipeline;
	if (pipeline_v->commands)
		destroy_list(&pipeline_v->commands, free_command);
	free(pipeline_v);
	*pipeline = NULL;
}

void	free_command(void *value)
{
	t_command	*command;

	command = (t_command *)value;
	destroy_command(&command);
}
