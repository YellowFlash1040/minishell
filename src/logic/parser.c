/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:27:17 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/16 14:37:58 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse(char *string, t_prompt **prompt)
{
	int	result;

	(void)string;
	result = build_prompt(prompt);
	if (result != SUCCESS)
		return (result);
	return (SUCCESS);
}

/*
I can split all of the commands using pipes '|' with ft_split function
and then inside each of the commands the first string always supposed to be
*/