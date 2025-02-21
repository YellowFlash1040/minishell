/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:52:04 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/20 14:01:14 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "command.h"
# include <stdlib.h>

# define PIPE_INIT_ERR 170

typedef enum e_pipe_end
{
	READ_END = 0,
	WRITE_END = 1
}				t_pipe_end;

typedef struct pipe
{
	t_command	*cmd1;
	t_command	*cmd2;
}				t_pipe;

t_pipe			*init_pipe(void);
void			destroy_pipe(t_pipe **pipe);

#endif
