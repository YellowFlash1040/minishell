/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:12:56 by ismo              #+#    #+#             */
/*   Updated: 2025/03/21 17:50:01 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>

t_token	*init_token()
{
	t_token *token;
	token = (t_token *)malloc(sizeof(token));
	if (!token)
		return (NULL);
	token->value = NULL;
	return (token);
}

void	destroy_token(t_token *token)
{
	if (!token)
		return ;
	if (token->value)
		free(token->value);
	free(token);
}

void	free_token(void *tok)
{
	destroy_token((t_token *)tok);
}
