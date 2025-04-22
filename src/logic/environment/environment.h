/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:38:44 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/22 16:27:18 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "list.h"
# include "variable.h"
# include "string_array.h"
# include "global_status_codes.h"
# include "converter.h"

t_list			*init_environment(char *envp[]);
void			destroy_environment(t_list **environment);
int				set_env_variable_int(t_list *env, t_string name, int value,
					bool is_exported);
int				set_env_variable(t_list *env, t_string name, t_string value,
					bool is_exported);
int				unset_env_variable(t_list *env, t_string name);
t_string		get_env_variable(t_list *env, t_string name);
t_string_array	construct_environment_for_export(t_list *env);

#endif
