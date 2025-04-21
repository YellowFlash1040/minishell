/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:25:40 by ismo              #+#    #+#             */
/*   Updated: 2025/04/02 15:42:50 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int	parse_pipeline(t_list *tokens, t_pipeline **pipeline, t_list *env);
int	parse_variable(t_list *tokens, char **name, char **value);
#endif
