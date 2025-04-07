/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander_utils.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 15:21:46 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/07 15:21:47 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_UTILS_H
# define EXPANDER_UTILS_H

char	*dup_env_var(t_list *env, char *name);
char	*expand_double_quote(t_list *env, char	*str);
#endif
