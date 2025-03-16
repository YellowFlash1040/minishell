/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:52:11 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/16 14:09:59 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list_node	*find_node(void *value, t_list *list, bool (*compare)(void*, void*))
{
	t_list_node	*node;

	if (!value || !list || !compare)
		return (NULL);
	node = list->head;
	while (node)
	{
		if (compare(node->value, value))
			return (node);
		node = node->next;
	}
	return (NULL);
}
