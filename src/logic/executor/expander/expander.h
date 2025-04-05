/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 00:45:36 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/04 17:04:53 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

void	expand_variable(t_list *env, t_variable *variable);
void	expand_command(t_command *command);
void	expand_commands(t_list **commands);
#endif
