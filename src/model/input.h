/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:52:01 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/19 18:52:03 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "list.h"
# include "prompt.h"
# include <stdlib.h>

# define INPUT_INIT_ERR 150

typedef struct input
{
	t_list	*prompts;
}			t_input;

t_input		*init_input(void);
void		destroy_input(t_input **input);

#endif
