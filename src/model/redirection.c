/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:19:10 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 19:17:13 by akovtune         ###   ########.fr       */
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
	if (redirection->target)
		destroy_redirection_target(&redirection->target);
	free(redirection);
	*redirection_ref = NULL;
}
//I don't need to free redirection->stream, 
//since it will be always bounded against one of the
//command->input/output/error_stream
//and those will be freed inside destroy_command() function
