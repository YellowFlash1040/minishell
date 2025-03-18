/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 14:22:40 by ismo          #+#    #+#                 */
/*   Updated: 2025/03/17 13:28:42 by ismo          ########   odam.nl         */
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
#endif
