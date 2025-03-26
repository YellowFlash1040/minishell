/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:57:15 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/20 12:41:13 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "string.h"

t_list	*init_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;
	return (list);
}

void	destroy_list(t_list **list_ref, void (*free_value)(void *))
{
	t_list	*list;

	if (!list_ref)
		return ;
	list = *list_ref;
	clear_list(list, free_value);
	free(list);
	*list_ref = NULL;
}

t_list_node	*get_node(int index, t_list *list)
{
	int			i;
	t_list_node	*node;

	if (!list || !list->head)
		return (NULL);
	i = -1;
	node = list->head;
	while (++i < index)
		node = node->next;
	return (node);
}
