/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:48:57 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/16 18:13:02 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "echo.h"
# include "cd.h"
# include "export.h"
# include "set.h"
# include "unset.h"
# include "env.h"
# include "pwd.h"
# include "exit_builtin.h"

typedef int	(*t_builtin)(t_command *command);

bool	is_builtin(t_string binary_name);
int		launch_builtin(t_command *command);

#endif

// ◦ echo with option -n
// ◦ cd with only a relative or absolute path
// ◦ pwd with no options
// ◦ export with no options
// ◦ unset with no options
// ◦ env with no options or arguments
// ◦ exit with no options