/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:22:40 by ismo              #+#    #+#             */
/*   Updated: 2025/03/21 17:55:12 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# define OPERATORS "<|>$\'\""

typedef enum token_type {
	SingleQuote,
	DoubleQuote,
	RedirInput,
	RedirOutput,
	RedirDelim,
	RedirAppend,
	Pipe,
	EnvVariable,
	Word,
	EndOfInput
} t_token_type;

typedef struct token {
	t_token_type type;
	char		*value;
} t_token;

t_token	*init_token();
void	destroy_token(t_token *token);
void	free_token(void *tok);
#endif
