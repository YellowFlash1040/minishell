/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:52:04 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/19 18:52:06 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "command.h"
# include <stdlib.h>

# define PIPE_INIT_ERR

typedef struct pipe
{
	t_command	*cmd1;
	t_command	*cmd2;
}				t_pipe;

t_pipe			*init_pipe(void);
void			destroy_pipe(t_pipe **pipe);

#endif
