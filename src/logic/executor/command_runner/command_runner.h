/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_runner.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/02/19 18:34:16 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/20 17:13:28 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_RUNNER_H
# define COMMAND_RUNNER_H

# include "builtins.h"
# include "error_printer.h"
# include <errno.h>

// # define CHILD_PROCESS pid == 0

# define BINARY_LAUNCH_ERR 190
# define CHILD_HANDLER_ERR 191
# define FORCED_PROCESS_EXIT_ERR 192
# define FORK_FUNC_ERR 193
# define CLOSE_FUNC_ERR 194
# define UNKNOWN_PROC_EXIT_STATUS_ERR 195
# define WRITE_FUNC_ERR 196
# define FILE_ACCESS_ERR 197

int	run_a_command(t_command *command);

#endif