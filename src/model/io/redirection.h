/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:13:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 16:19:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "stream.h"
# include "redirection_target.h"

typedef struct redirection
{
	/// @brief Default: `NULL`
	t_stream				*stream;
	/// @brief Default: `NULL`
	t_redirection_target	*target;
}	t_redirection;

t_redirection	*init_redirection(void);
void			destroy_redirection(t_redirection **redirection_ref);

#endif
