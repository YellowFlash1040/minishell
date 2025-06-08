/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:19:52 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/22 18:28:49 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array.h"

t_string_array	init_string_array(int size)
{
	t_string_array	string_array;
	int				i;

	string_array = (t_string_array)malloc(sizeof(t_string) * (size + 1));
	if (!string_array)
		return (NULL);
	i = -1;
	while (++i < size)
		string_array[i] = NULL;
	string_array[size] = NULL;
	return (string_array);
}

void	destroy_string_array(t_string_array *string_array_ref)
{
	t_string_array	string_array;
	int				i;

	if (!string_array_ref || !*string_array_ref)
		return ;
	string_array = *string_array_ref;
	i = -1;
	while (string_array[++i])
		free(string_array[i]);
	free(string_array);
	*string_array_ref = NULL;
}

int	get_str_arr_length(t_string_array arr)
{
	int	i;

	if (!arr)
		return (-1);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

t_string_array	copy_str_array(t_string_array arr, int start_index,
	int end_index)
{
	t_string_array	copy_arr;
	t_string		temp;
	int				i;

	if (arr && end_index == -1)
		end_index = get_str_arr_length(arr);
	if (!arr || start_index < 0 || end_index < 0 || end_index < start_index)
		return (NULL);
	copy_arr = init_string_array(end_index - start_index + 1);
	if (!copy_arr)
		return (NULL);
	i = -1;
	while (arr[++i])
	{
		temp = ft_strdup(arr[i]);
		if (!temp)
			return (destroy_string_array(&copy_arr), NULL);
		copy_arr[i] = temp;
	}
	return (copy_arr);
}

int	index_of_string(t_string_array arr, t_string value)
{
	int	i;

	if (!arr)
		return (-1);
	i = -1;
	while (arr[++i])
		if (ft_strcmp(arr[i], value))
			return (i);
	return (-1);
}
