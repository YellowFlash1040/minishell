/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   non_terminals.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 15:58:05 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/01 15:59:17 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NON_TERMINALS_H
# define NON_TERMINALS_H

int	nt_file(t_list *tokens, int *depth, char **blob);
int	nt_comb(t_list *tokens, int *depth, char **comb);
int	nt_redir(t_list *tokens, int *depth, t_command **command);
int	nt_command(t_list *tokens, int *depth, t_command **command);
int	nt_pipeline(t_list *tokens, int *depth, t_pipeline **pipeline, t_list *env);
#endif
