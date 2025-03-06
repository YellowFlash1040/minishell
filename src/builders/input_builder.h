/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_builder.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:16:13 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/19 18:48:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_BUILDER_H
# define INPUT_BUILDER_H

# include "global_status_codes.h"
# include "input.h"

# define EMPTY_INPUT_REF_ERR 130
# define PROMPTS_LIST_INIT_ERR 131

int	build_input(t_input **input);

#endif
