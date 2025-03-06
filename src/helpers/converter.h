/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:51:35 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/19 18:51:35 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include "list.h"

/// @brief Converts a list of strings into a NULL-terminated array of strings
/// @param list a list of strings
/// @return An array of strings
char	**convert_list_to_array(t_list *list);

#endif