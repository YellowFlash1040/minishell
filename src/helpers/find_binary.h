/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_binary.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:41:13 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/09 17:13:18 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_BINARY_H
# define FIND_BINARY_H

# include "string_array.h"
# include "global_status_codes.h"
# include <stdlib.h>
# include <unistd.h>

# define EMPTY_PATH_ERR 160
# define MALLOC_FAIL_ERR 161

int	find_binary(t_string path, t_string *result);

#endif
