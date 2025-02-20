/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:04:24 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/14 16:13:36 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt_builder.h"

int	build_prompt(t_prompt **prompt)
{
	t_prompt	*prompt_v;

	if (!prompt)
		return (EMPTY_PROMPT_REF_ERR);
	*prompt = init_prompt();
	if (!*prompt)
		return (PROMPT_INIT_ERR);
	prompt_v = *prompt;
	prompt_v->pipelines = init_list();
	if (!prompt_v->pipelines)
		return (destroy_prompt(prompt), PIPELINES_LIST_INIT_ERR);
	return (SUCCESS);
}
