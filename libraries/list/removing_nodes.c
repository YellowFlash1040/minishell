/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removing_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:22:06 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/16 14:21:43 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

static void	remove_node(t_list_node *node, t_list_node *prev_node, t_list *list,
				void (*free_value)(void *));

bool	remove_from_list(void *value, t_list *list, bool (*compare)(void *,
			void *), void (*free_value)(void *))
{
	t_list_node	*node;
	t_list_node	*prev_node;

	if (!list || !value || !compare || !free_value)
		return (false);
	node = list->head;
	prev_node = NULL;
	while (node)
	{
		if (compare(node->value, value))
		{
			remove_node(node, prev_node, list, free_value);
			return (true);
		}
		prev_node = node;
		node = node->next;
	}
	return (true);
}

static void	remove_node(t_list_node *node, t_list_node *prev_node, t_list *list,
		void (*free_value)(void *))
{
	if (prev_node)
		prev_node->next = node->next;
	else
		list->head = list->head->next;
	if (node == list->tail)
		list->tail = prev_node;
	free_value(node->value);
	free(node);
	list->count--;
}

t_list_node	*pop(t_list *list)
{
	t_list_node	*node;

	if (!list || !list->head)
		return (NULL);
	node = list->head;
	list->head = list->head->next;
	if (!list->head)
		list->tail = NULL;
	node->next = NULL;
	list->count--;
	return (node);
}

void	clear_list(t_list *list, void (*free_value)(void *))
{
	t_list_node	*temp;

	if (!list || !list->head)
		return ;
	while (list->count > 0)
	{
		temp = list->head->next;
		if (list->head->value && free_value)
			free_value(list->head->value);
		free(list->head);
		list->head = temp;
		list->count--;
	}
	list->tail = NULL;
}
