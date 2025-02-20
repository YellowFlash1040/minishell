/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:54:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/19 18:54:18 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	free_prompt(void *value);

t_input	*init_input(void)
{
	t_input	*input;

	input = (t_input *)malloc(sizeof(t_input));
	if (!input)
		return (NULL);
	input->prompts = NULL;
	return (input);
}

void	destroy_input(t_input **input)
{
	t_input	*input_v;

	if (!input || !*input)
		return ;
	input_v = *input;
	if (input_v->prompts)
		clear_list(input_v->prompts, free_prompt);
	free(input_v->prompts);
	free(*input);
	*input = NULL;
}

void	free_prompt(void *value)
{
	t_prompt	*prompt;

	prompt = (t_prompt *)value;
	destroy_prompt(&prompt);
}
