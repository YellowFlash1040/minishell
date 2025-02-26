/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:51:32 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/19 18:51:33 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"

char	**convert_list_to_array(t_list *list)
{
	t_list_node	*current_node;
	char		**strings;
	int			i;

	if (list == NULL || list->head == NULL)
		return (NULL);
	strings = malloc(sizeof(char *) * (list->count + 1));
	if (!strings)
		return (NULL);
	current_node = list->head;
	i = -1;
	while (++i < list->count)
	{
		strings[i] = (char *)current_node->value;
		current_node = current_node->next;
	}
	strings[i] = NULL;
	return (strings);
}
