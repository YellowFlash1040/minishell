/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibenne <ibenne@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/16 14:02:33 by akovtune      #+#    #+#                 */
/*   Updated: 2025/04/09 19:18:18 by ismo          ########   odam.nl         */
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
# include "error_printer.h"

int	export(t_command *command);

#endif
