/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:15:43 by ismo              #+#    #+#             */
/*   Updated: 2025/04/02 14:07:24 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_UTILS_H
# define TOKENIZER_UTILS_H

int		get_wlen(char *prompt, int *i, char *delims);
char	*scan_word(char *prompt, int *i, char *delims);
char	*read_quote(char quote, char *prompt, int *i);
#endif
