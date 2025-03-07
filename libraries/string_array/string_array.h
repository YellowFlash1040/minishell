/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:19:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/07 16:25:33 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_ARRAY_H
# define STRING_ARRAY_H

# include <stdlib.h>
#include "ft_string.h"

# define STRING_ARRAY_INIT_ERR 

typedef t_string*	t_string_array;

t_string_array	init_string_array(int size);
void			destroy_string_array(t_string_array* string_array);

#endif
