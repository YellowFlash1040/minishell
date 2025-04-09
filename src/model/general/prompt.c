/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:05:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/14 15:05:40 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void		free_pipeline(void *value);

t_prompt	*init_prompt(void)
{
	t_prompt	*prompt;

	prompt = (t_prompt *)malloc(sizeof(t_prompt));
	if (!prompt)
		return (NULL);
	prompt->pipelines = NULL;
	prompt->status_code = 0;
	return (prompt);
}

void	destroy_prompt(t_prompt **prompt)
{
	t_prompt	*prompt_v;

	if (!prompt || !*prompt)
		return ;
	prompt_v = *prompt;
	if (prompt_v->pipelines)
		clear_list(prompt_v->pipelines, free_pipeline);
	free(prompt_v->pipelines);
	free(*prompt);
	*prompt = NULL;
}

void	free_pipeline(void *value)
{
	t_pipeline	*pipeline;

	pipeline = (t_pipeline *)value;
	destroy_pipeline(&pipeline);
}
