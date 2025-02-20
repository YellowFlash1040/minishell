/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_builder.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:04:27 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/14 14:21:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_BUILDER_H
# define PROMPT_BUILDER_H

# include "global_status_codes.h"
# include "prompt.h"

# define EMPTY_PROMPT_REF_ERR 100
# define PIPELINES_LIST_INIT_ERR 101

int	build_prompt(t_prompt **prompt);

#endif
