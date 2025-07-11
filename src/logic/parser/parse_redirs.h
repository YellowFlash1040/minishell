/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_redirs.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/31 00:49:10 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/06 20:08:02 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_REDIRS_H
# define PARSE_REDIRS_H

int	add_redirection(t_command **command,
		char *filename,
		t_token_type redir_type);
#endif
