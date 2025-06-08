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

void	free_command(void *value);
void	free_pipe(void *value);

t_pipeline	*init_pipeline(void)
{
	t_pipeline	*pipeline;

	pipeline = (t_pipeline *)malloc(sizeof(t_pipeline));
	if (!pipeline)
		return (NULL);
	pipeline->commands = NULL;
	pipeline->status_code = 0;
	pipeline->pipes = NULL;
	return (pipeline);
}

void	destroy_pipeline(t_pipeline **pipeline_ref)
{
	t_pipeline	*pipeline;

	if (!pipeline_ref || !*pipeline_ref)
		return ;
	pipeline = *pipeline_ref;
	if (pipeline->commands)
		destroy_list(&pipeline->commands, free_command);
	if (pipeline->pipes)
		destroy_list(&pipeline->pipes, free_pipe);
	free(pipeline);
	*pipeline_ref = NULL;
}

void	free_command(void *value)
{
	t_command	*command;

	command = (t_command *)value;
	destroy_command(&command);
}

void	free_pipe(void *value)
{
	t_p1pe	*p1pe;

	p1pe = (t_p1pe *)value;
	destroy_p1pe(&p1pe);
}
