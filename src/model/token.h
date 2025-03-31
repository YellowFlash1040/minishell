/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibenne <ibenne@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 14:22:40 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/01 00:13:24 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# define OPERATORS "<|>$\'\""
# define OPERATORS_VAR "<|>$\'\"="

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
	EqualSign,
	EndOfInput
} t_token_type;

typedef struct token {
	t_token_type 	type;
	char			*value;
	char			seperator;
} t_token;

t_token	*init_token();
void	destroy_token(t_token *token);
void	free_token(void *tok);
#endif
