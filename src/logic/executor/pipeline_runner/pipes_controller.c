/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:30:59 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/13 19:35:16 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipes_controller.h"

void	free_pipe(void *value);

int	create_all_pipes(t_list *pipes, int amount)
{
	int		result;
	t_p1pe	*p1pe;
	int		i;

	i = -1;
	while (++i < amount)
	{
		p1pe = init_p1pe();
		if (!p1pe)
			return (destroy_list(&pipes, free_pipe), FAILURE);
		result = add_to_list(pipes, p1pe);
		if (result != true)
			return (destroy_p1pe(&p1pe),
				destroy_list(&pipes, free_pipe), FAILURE);
	}
	return (SUCCESS);
}

int	close_all_pipes(t_list *pipes)
{
	t_list_node	*node;
	t_p1pe		*p1pe;

	if (!pipes)
		return (FAILURE);
	node = pipes->head;
	while (node)
	{
		p1pe = (t_p1pe *)node->value;
		close(p1pe->read_end);
		close(p1pe->write_end);
		node = node->next;
	}
	return (SUCCESS);
}
