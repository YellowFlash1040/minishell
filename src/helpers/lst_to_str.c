/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:21:07 by ismo              #+#    #+#             */
/*   Updated: 2025/04/02 15:10:40 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "list.h"
#include <stdbool.h>

int	lst_strlen(t_list **list)
{
	int			len;
	t_list_node	*node;

	len = 0;
	node = (*list)->head;
	while (node)
	{
		len += ft_strlen((char *) node->value);
		node = node->next;
	}
	return (len);
}

char	*lst_to_str(t_list **list)
{
	int			i;
	int			j;
	t_list_node	*node;
	char		*res;

	res = (char *)malloc(lst_strlen(list) + 1);
	if (!res)
		return (NULL);
	i = 0;
	node = (*list)->head;
	while (node)
	{
		j = 0;
		while (((char *)node->value)[j])
			res[i++] = ((char *)node->value)[j++];
		node = node->next;
	}
	res[i] = '\0';
	return (res);
}
