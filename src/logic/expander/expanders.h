/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanders.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:48:36 by ismo              #+#    #+#             */
/*   Updated: 2025/04/18 16:30:33 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDERS_H
# define EXPANDERS_H

char	*expand_comb(t_list *env, char *arg);
int		expand_path(t_list *env, t_file *file);
int		expand_arguments(t_command *command);
#endif
