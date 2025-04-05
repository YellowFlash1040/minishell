/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expanders.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 16:48:36 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/04 17:06:42 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDERS_H
# define EXPANDERS_H

char	*expand_comb(t_list *env, char *arg);
void	expand_path(t_list *env, t_file *file);
int		expand_arguments(t_command *command);
#endif
