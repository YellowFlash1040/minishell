/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 15:25:40 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/01 15:25:40 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int	parse_tokens(t_list *tokens, t_pipeline **pipeline, t_list *env);
int	parse_variable(t_list *tokens, char **name, char **value);
#endif
