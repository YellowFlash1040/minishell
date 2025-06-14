/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   variable.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akovtune <akovtune@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 18:29:18 by akovtune      #+#    #+#                 */
/*   Updated: 2025/03/29 16:47:55 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_H
# define VARIABLE_H

# include "ft_string.h"

typedef struct variable
{
	t_string	name;
	t_string	value;
	bool		is_exported;
}	t_variable;

t_variable	*init_variable(t_string name, t_string value);
void		destroy_variable(t_variable **variable);

#endif
