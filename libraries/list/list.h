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

typedef struct list
{
	int					count;
	t_list_node			*head;
	t_list_node			*tail;
}						t_list;

/**
 * @brief Initializes an empty linked list.
 *
 * This function creates and initializes a new empty linked list. The list's
 * head is set to NULL, and the count of elements is set to 0.
 *
 * @return A pointer to the newly created empty list, 
 * or NULL if memory allocation fails.
 */
t_list		*init_list(void);

void		destroy_list(t_list **list_ref, void (*free_value)(void *));

/**
 * @brief Clears all elements of the list and frees associated memory.
 *
 * This function iterates through the list, frees each node's value using
 * the provided `free_value` function, 
 * and then frees the nodes and the list itself.
 *
 * @param list The list to clear.
 * @param free_value A function to free each node's value, 
 * or NULL if no freeing is needed.
 */
void		clear_list(t_list *list, void (*free_value)(void *));

/**
 * @brief Creates a new node with a specified value.
 *
 * This function allocates memory for a new list node and assigns the given
 * `value` to the node's value field. 
 * The node's next pointer is initialized to NULL.
 *
 * @param value The value to store in the new node.
 * @return A pointer to the newly created node, 
 * or NULL if memory allocation fails.
 */
t_list_node	*create_node(void *value);

/**
 * @brief Adds a new node to the end of the list.
 *
 * This function adds the specified `new_node` 
 * to the end of the linked list `list`.
 * If the list is empty, the node becomes the head.
 *
 * @param new_node The node to add to the list.
 * @param list The list to add the node to.
 */
void		push(t_list_node *new_node, t_list *list);

/**
 * @brief Removes and returns the first node from the list.
 *
 * This function removes the head node of the list, 
 * updates the head to the next node,
 * and returns the removed node. The list count is decremented.
 *
 * @param list The list from which to pop the first node.
 * @return A pointer to the removed node, or NULL if the list is empty.
 */
t_list_node	*pop(t_list *list);

/**
 * @brief Adds a new value to the list.
 *
 * This function creates a new node with the specified `value` and adds it to
 * the list by calling the `push` function.
 *
 * @param list The list to add the new value to.
 * @param value The value to add to the list.
 * @return true if the node was successfully added, 
 * or false if memory allocation failed.
 */
bool		add_to_list(t_list *list, void *value);

/**
 * @brief Retrieves the node at a specified index in the list.
 *
 * This function returns the node at the given index in the linked list `list`.
 * If the index is out of bounds, it returns NULL.
 *
 * @param index The index of the node to retrieve.
 * @param list The list to retrieve the node from.
 * @return A pointer to the node at the specified index, 
 * or NULL if the index is out of bounds.
 */
t_list_node	*get_node(int index, t_list *list);

t_list_node	*find_node(void *value, t_list *list,
				bool (*compare)(void*, void*));

bool		remove_from_list(void *value, t_list *list,
				bool (*compare)(void *, void *), void (*free_value)(void *));

#endif