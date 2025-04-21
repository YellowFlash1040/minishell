/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:22:38 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/15 18:22:58 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

bool	add_to_list(t_list *list, void *value)
{
	t_list_node	*node;

	node = create_node(value);
	if (!node)
		return (false);
	push(node, list);
	return (true);
}

t_list_node	*create_node(void *value)
{
	t_list_node	*node;

	node = (t_list_node *)malloc(sizeof(t_list_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push(t_list_node *new_node, t_list *list)
{
	if (!list || !new_node)
		return ;
	if (!list->head)
	{
		list->head = new_node;
		list->tail = new_node;
	}
	else
	{
		list->tail->next = new_node;
		list->tail = new_node;
	}
	list->count++;
}
