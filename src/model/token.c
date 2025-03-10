/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 15:12:56 by ismo          #+#    #+#                 */
/*   Updated: 2025/03/10 15:28:43 by ismo          ########   odam.nl         */
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
