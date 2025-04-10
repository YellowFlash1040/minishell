/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:33:09 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 18:32:03 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include "command.h"
# include "redirection_processor.h"

typedef struct stream_binding
{
	int				standard_fd;
	t_stream		*stream;
}	t_stream_binding;

#endif