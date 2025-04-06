/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:19:10 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 16:20:42 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

t_redirection	*init_redirection(void)
{
	t_redirection	*redirection;

	redirection = (t_redirection *)malloc(sizeof(t_redirection));
	if (!redirection)
		return (NULL);
	redirection->stream = NULL;
	redirection->target = NULL;
	return (redirection);
}

void	destroy_redirection(t_redirection **redirection_ref)
{
	t_redirection	*redirection;

	if (!redirection_ref || !*redirection_ref)
		return ;
	redirection = *redirection_ref;
	if (redirection->stream)
		destroy_stream(&redirection->stream);
	if (redirection->target)
		destroy_redirection_target(&redirection->target);
	free(redirection);
	*redirection_ref = NULL;
}
