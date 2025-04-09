/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibenne <ibenne@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/16 17:34:39 by akovtune      #+#    #+#                 */
/*   Updated: 2025/04/09 19:23:31 by ismo          ########   odam.nl         */
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
# include "error_printer.h"

int	set(t_command *command);

#endif
