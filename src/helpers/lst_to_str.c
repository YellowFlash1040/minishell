/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_to_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/29 17:21:07 by ismo          #+#    #+#                 */
/*   Updated: 2025/03/29 18:39:31 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "list.h"

char	*lst_to_str(t_list **list)
{
	int			n;
	int			i;
	int			j;
	t_list_node	*node;
	char		*res;

	n = 0;
	j = 0;
	while ((node = get_node(n++, *list)))
		j += ft_strlen((char *) node->value);
	res = (char *)malloc(j + 1);
	if (!res)
		return (NULL);
	n = 0;
	i = 0;
	while ((node = get_node(n++, *list)))
	{
		j = 0;
		while (((char *)node->value)[j])
			res[i++] = ((char *)node->value)[j++];
	}
	res[i] = '\0';
	return (res);
}
