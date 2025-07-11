/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:19:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/27 17:34:45 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_ARRAY_H
# define STRING_ARRAY_H

# include <stdlib.h>
# include "ft_string.h"

# define STRING_ARRAY_INIT_ERR 29

typedef t_string*	t_string_array;

t_string_array	init_string_array(int size);
void			destroy_string_array(t_string_array *string_array);
int				get_str_arr_length(t_string_array arr);
t_string_array	copy_str_array(t_string_array arr, int start_index,
					int end_index);
int				index_of_string(t_string_array arr, t_string value);

#endif
