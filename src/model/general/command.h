/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:54:06 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/20 14:48:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "stream.h"
# include "redirection.h"
# include "list.h"
# include "string_array.h"
# include <wait.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# define COMMAND_INIT_ERR 10

typedef struct command
{
	/// @brief Default: `-1`
	pid_t			id;
	t_string		executable;
	t_string_array	arguments;
	t_stream		*input_stream;
	t_stream		*output_stream;
	t_stream		*error_stream;
	/// @brief Default: `NULL`
	t_list			*redirections;
	/// @brief Default: `0`
	int				exit_status_code;
	/// @brief Default: `true`
	bool			needs_a_subshell;
	/// @brief Default: `NULL`
	t_list			*environment;
	/// @brief Default: `false`
	bool			is_in_pipeline;
	/// @brief Default: `NULL`
	t_list			*pipes;
}					t_command;

t_command			*init_command(void);
void				destroy_command(t_command **command);

#endif
