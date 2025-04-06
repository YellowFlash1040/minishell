/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:24:36 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 19:05:14 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "ft_string.h"

typedef struct heredoc
{
	/// @brief Default: `NULL`
	t_string	delimiter;
	/// @brief Default: `-1`
	int			fd;
}	t_heredoc;

t_heredoc	*init_heredoc(void);
void		destroy_heredoc(t_heredoc **heredoc_ref);

#endif
