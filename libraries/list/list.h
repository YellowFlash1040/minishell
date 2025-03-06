/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:57:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/19 18:57:18 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct list_node
{
	void				*value;
	struct list_node	*next;
}						t_list_node;

typedef struct cirular_list
{
	int					count;
	t_list_node			*head;

}						t_list;

t_list					*init_list(void);
t_list_node				*create_node(void *value);
void					clear_list(t_list *list, void (*free_value)(void *));
t_list_node				*pop(t_list *list);
void					push(t_list_node *node, t_list *list);
bool					add_to_list(t_list *list, void *value);
t_list_node				*get_node(int index, t_list *list);

#endif