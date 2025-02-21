/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_builder.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:42:10 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/20 14:17:43 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_BUILDER_H
# define PIPE_BUILDER_H

# define EMPTY_PIPE_REF_ERR 160
# define COMMAND_BUILDER_ERR 161

# include "command_builder.h"
# include "pipe.h"

int	build_pipe(t_pipe **pipe);

#endif
