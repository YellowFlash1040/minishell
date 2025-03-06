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
#include <stdio.h>

t_list	*init_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->count = 0;
	return (list);
}

void	clear_list(t_list *list, void (*free_value)(void *))
{
	t_list_node	*temp;

	if (!list || !list->head)
		return ;
	while (list->count--)
	{
		temp = list->head->next;
		if (list->head->value && free_value)
			free_value(list->head->value);
		free(list->head);
		list->head = temp;
	}
	free(list);
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
	t_list_node	*node;
	t_list_node	*prev_node;

	if (!list || !new_node)
		return ;
	node = list->head;
	prev_node = NULL;
	while (node)
	{
		prev_node = node;
		node = node->next;
	}
	if (!list->head)
		list->head = new_node;
	else
		prev_node->next = new_node;
	list->count++;
}

t_list_node	*pop(t_list *list)
{
	t_list_node	*node;

	if (!list || !list->head)
		return (NULL);
	node = list->head;
	list->head = list->head->next;
	node->next = NULL;
	list->count--;
	return (node);
}
