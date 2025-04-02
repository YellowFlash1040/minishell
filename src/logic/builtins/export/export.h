/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:02:33 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/02 15:36:00 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include "environment.h"
# include "command.h"
# include "pipeline.h"
# include "token.h"
# include "tokenizer.h"
# include "parser.h"

int	export(t_command *command);

#endif
