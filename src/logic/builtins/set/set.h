/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:34:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/02 15:41:37 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H

# include "environment.h"
# include "command.h"
# include "pipeline.h"
# include "token.h"
# include "tokenizer.h"
# include "parser.h"

int	set(t_command *command);

#endif
