/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer_utils.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 15:15:43 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/01 15:24:27 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_UTILS_H
# define TOKENIZER_UTILS_H

int		get_wlen(char *prompt, int *i, int is_variable);
char	*scan_word(char *prompt, int *i, int is_variable);
char	*read_quote(char quote, char *prompt, int *i);
#endif
