/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:05:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/19 18:47:37 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_H
# define PIPELINE_H

# include "command.h"
# include "list.h"
# include <stdlib.h>

# define PIPELINE_INIT_ERR 20

typedef struct pipeline
{
	t_list	*commands;
	int		status_code;
}			t_pipeline;

t_pipeline	*init_pipeline(void);
void		destroy_pipeline(t_pipeline **pipeline);

#endif
