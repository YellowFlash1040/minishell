/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p1pe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:15:22 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/18 18:37:35 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P1PE_H
# define P1PE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define P1PE_INIT_ERR 1

typedef enum e_pipe_end
{
	READ_END = 0,
	WRITE_END = 1
}	t_pipe_end;

typedef struct p1pe
{
	int	read_end;
	int	write_end;
}	t_p1pe;

t_p1pe	*init_p1pe(void);
void	destroy_p1pe(t_p1pe **p1pe_ref);

#endif
