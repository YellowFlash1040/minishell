/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_target.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:55:29 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 16:17:54 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_TARGET_H
# define REDIRECTION_TARGET_H

# include "file.h"
# include "heredoc.h"
# include <stdlib.h>

# define REDIRECTION_TARGET_INIT_ERR 1

typedef enum target_type
{
	FILE_TYPE, //word FILE was already taken by some of the standard libraries
	HERE_DOC,
	PIPE_TYPE
}	t_target_type;

typedef struct redirection_target
{
	/**
	 * @brief Default: `NULL`. 
	 * Possible values: `t_file *`, `t_heredoc *`, `int *`
	 */
	void				*value;
	/**
	* @brief Default: `FILE`. 
	* Possible values: `FILE`, `HERE_DOC`, `PIPE_TYPE`
	*/
	t_target_type		type;
}	t_redirection_target;

t_redirection_target	*init_redirection_target(void);
void					destroy_redirection_target(
							t_redirection_target **target_ref);

#endif
