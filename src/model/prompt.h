/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:05:41 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/19 18:47:32 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "list.h"
# include "pipeline.h"
# include <stdlib.h>

# define PROMPT_INIT_ERR 30

typedef struct prompt
{
	t_list	*pipelines;
	int		status_code;
}			t_prompt;

t_prompt	*init_prompt(void);
void		destroy_prompt(t_prompt **prompt);

#endif
