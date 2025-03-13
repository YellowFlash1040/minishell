/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:38:44 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/10 19:51:32 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "list.h"
# include "string_array.h"
# include "variable.h"

#endif

// typedef struct variable
// {
// 	t_string name;
// 	t_string value;
// 	bool is_exported;
// } t_variable;

// t_list *environment; //list of t_variable

// typedef struct command
// {
// 	pid_t			id;
// 	t_string		executable;
// 	t_string_array	arguments;
// 	t_file			*input_file;
// 	t_file			*output_file;
// 	t_file			*error_file;
// 	int				exit_status_code;
// 	int				unused_pipe_end;
// 	t_list			*environment; //link/reference to the "global" environment
// 	t_list			*variables; //list of local variables of type t_string
// } t_command;

// node = environment->head;
// while (node)
// {
// 	local_node = variables->head;
// 	while (local_node)
// 	{
// 		if (local_node->value == node->value->name)
// 		{
// 			arguments[i] = node->value->value;
// 		}
// 	}
// }
