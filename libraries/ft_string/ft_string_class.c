/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_class.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:51:41 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 18:58:33 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string	init_string(int size)
{
	t_string	string;

	string = (t_string)malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	string[size] = '\0';
	return (string);
}

void	destroy_string(t_string *string_ref)
{
	t_string	string;

	if (!string_ref || !*string_ref)
		return ;
	string = *string_ref;
	free(string);
	*string_ref = NULL;
}
