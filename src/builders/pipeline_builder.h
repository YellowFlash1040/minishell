/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_builder.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:07:45 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/21 17:53:48 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_BUILDER_H
# define PIPELINE_BUILDER_H

# include "global_status_codes.h"
# include "pipeline.h"

# define EMPTY_PIPELINE_REF_ERR 110
# define COMMANDS_LIST_INIT_ERR 111
# define PIPES_LIST_INIT_ERR 112

int	build_pipeline(t_pipeline **pipeline);

#endif
