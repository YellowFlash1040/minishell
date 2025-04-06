/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processor.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:37:20 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 16:50:25 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PROCESSOR_H
# define FILE_PROCESSOR_H

# include "file.h"
# include "error_printer.h"
# include <stdbool.h>

# define FILE_ACCESS_ERR 197

int	process_file(t_file *file);

#endif