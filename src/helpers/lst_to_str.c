/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_to_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/29 17:21:07 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/01 16:35:54 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "list.h"

int	lst_strlen(t_list **list)
{
	int			n;
	int			j;
	t_list_node	*node;

	n = 0;
	j = 0;
	node = get_node(n++, *list);
	while (node)
	{
		j += ft_strlen((char *) node->value);
		node = get_node(n++, *list);
	}
	return (j);
}

char	*lst_to_str(t_list **list)
{
	int			n;
	int			i;
	int			j;
	t_list_node	*node;
	char		*res;

	res = (char *)malloc(lst_strlen(list) + 1);
	if (!res)
		return (NULL);
	n = 0;
	i = 0;
	node = get_node(n++, *list);
	while (node)
	{
		j = 0;
		while (((char *)node->value)[j])
			res[i++] = ((char *)node->value)[j++];
		node = get_node(n++, *list);
	}
	res[i] = '\0';
	return (res);
}
