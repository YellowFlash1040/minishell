/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:22:01 by ismo              #+#    #+#             */
/*   Updated: 2025/04/02 15:06:03 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZERS_H
# define TOKENIZERS_H

int		tokenize_quote(t_token *token, char *prompt, int *i);
void	tokenize_redir(t_token *token, char *prompt, int *i);
void	tokenize_one(t_token *token, int *i, t_token_type type);
int		tokenize_env(t_token *token, char *prompt, int *i, int is_variable);
int		tokenize_word(t_token *token, char *prompt, int *i, int is_variable);
#endif
