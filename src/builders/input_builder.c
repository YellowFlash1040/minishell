/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:15:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/19 18:48:13 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_builder.h"

int	build_input(t_input **input)
{
	t_input	*input_v;

	if (!input)
		return (EMPTY_INPUT_REF_ERR);
	*input = init_input();
	if (!*input)
		return (INPUT_INIT_ERR);
	input_v = *input;
	input_v->prompts = init_list();
	if (!input_v->prompts)
		return (destroy_input(input), PROMPTS_LIST_INIT_ERR);
	return (SUCCESS);
}
