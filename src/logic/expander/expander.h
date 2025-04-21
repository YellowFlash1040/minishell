/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:45:36 by ismo              #+#    #+#             */
/*   Updated: 2025/04/18 16:25:21 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

int		expand_variable(t_list *env, t_variable *variable);
int		expand_command(t_command *command);
int		expand_commands(t_list **commands);
#endif
