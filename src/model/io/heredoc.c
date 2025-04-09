/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:26:01 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 19:05:40 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

t_heredoc	*init_heredoc(void)
{
	t_heredoc	*heredoc;

	heredoc = (t_heredoc *)malloc(sizeof(t_heredoc));
	if (!heredoc)
		return (NULL);
	heredoc->fd = -1;
	heredoc->delimiter = NULL;
	return (heredoc);
}

void	destroy_heredoc(t_heredoc **heredoc_ref)
{
	t_heredoc	*heredoc;

	if (!heredoc_ref || !*heredoc_ref)
		return ;
	heredoc = *heredoc_ref;
	if (heredoc->delimiter)
		free(heredoc->delimiter);
	free(heredoc);
	*heredoc_ref = NULL;
}
