/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:40:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/26 13:02:54 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_runner.h"

int	process_file(t_file *file);

int	process_intermediate_files(t_list *intermediate_files)
{
	int			result;
	t_file		*file;
	t_list_node	*node;
	int			i;

	node = intermediate_files->head;
	i = -1;
	while (++i < intermediate_files->count)
	{
		file = (t_file *)node->value;
		result = process_file(file);
		if (result != SUCCESS)
			return (result);
		close(file->fd);
		node = node->next;
	}
	return (SUCCESS);
}
