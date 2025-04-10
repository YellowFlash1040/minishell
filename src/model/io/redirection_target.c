/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_target.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:55:27 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/06 19:02:33 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection_target.h"

t_redirection_target	*init_redirection_target(void)
{
	t_redirection_target	*target;

	target = (t_redirection_target *)malloc(sizeof(t_redirection_target));
	if (!target)
		return (NULL);
	target->value = NULL;
	target->type = FILE_TYPE;
	return (target);
}

void	destroy_redirection_target(t_redirection_target **target_ref)
{
	t_redirection_target	*target;
	t_file					*file;
	t_heredoc				*heredoc;

	if (!target_ref || !*target_ref)
		return ;
	target = *target_ref;
	if (target->value)
	{
		if (target->type == FILE_TYPE)
		{
			file = (t_file *)target->value;
			destroy_file(&file);
		}
		else if (target->type == HERE_DOC)
		{
			heredoc = (t_heredoc *)target->value;
			destroy_heredoc(&heredoc);
		}
	}
	free(target);
	*target_ref = NULL;
}
