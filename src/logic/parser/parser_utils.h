/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 15:25:36 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/01 16:21:21 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

int		is_file(t_token_type type);
int		is_redir(t_token_type type);
t_token	*read_token(t_list *tokens, int index);
int		n_args(t_list *tokens, int index);
char	*quote_str(t_token *token);
#endif
