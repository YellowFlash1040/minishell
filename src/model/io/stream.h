/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:13:19 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 16:21:55 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_H
# define STREAM_H

# include <stdlib.h>
# include <unistd.h> //for dup2() and close()
# include <stdio.h> //for perror()
# include "global_status_codes.h"

# define STREAM_INIT_ERR 1
# define FD_DUP_ERR 142

typedef enum stream_type
{
	UNDEFINED_STREAM = -1,
	INPUT,
	OUTPUT,
	ERROR
}	t_stream_type;

typedef struct stream
{
	/// @brief Default: `-1`
	int				fd;
	/// @brief Default: `UNDEFINED_STREAM`. 
	///Possible values: `UNDEFINED_STREAM`, `INPUT`, `OUTPUT`, `ERROR`
	t_stream_type	type;
}	t_stream;

t_stream	*init_stream(void);
void		destroy_stream(t_stream **stream);
int			redirect(int old_fd, int new_fd);

#endif
