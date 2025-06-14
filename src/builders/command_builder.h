/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builder.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:44:26 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/19 18:44:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_BUILDER_H
# define COMMAND_BUILDER_H

# include "command.h"

# define EMPTY_COMMAND_REF_ERR 120
# define ARGUMENTS_LIST_INIT_ERR 121
# define ENV_VAR_LIST_INIT_ERR 122
# define INPUT_STREAM_INIT_ERR 123
# define OUTPUT_STREAM_INIT_ERR 124
# define ERROR_STREAM_INIT_ERR 125
# define LIST_INIT_ERR 126

int	build_command(t_command **command);

#endif
