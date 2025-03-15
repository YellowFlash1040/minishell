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

# include "file.h"
# include "list.h"
# include "string_array.h"
# include <wait.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# define COMMAND_INIT_ERR 10

typedef struct command
{
	pid_t			id;
	t_string		executable;
	t_string_array	arguments;
	t_string_array	environment;
	t_file			*input_file;
	t_file			*output_file;
	t_file			*error_file;
	int				exit_status_code;
	int				unused_pipe_end;
	bool			needs_a_subshell;
}					t_command;

t_command			*init_command(void);
void				destroy_command(t_command **command);

#endif
