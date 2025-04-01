/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizers.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 15:20:13 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/01 15:35:29 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "tokenizer_utils.h"

int	tokenize_quote(t_token *token, char *prompt, int *i)
{
	if (prompt[*i] == '\'')
	{
		token->value = read_quote('\'', prompt, i);
		token->type = SingleQuote;
	}
	else if (prompt[*i] == '"')
	{
		token->value = read_quote('"', prompt, i);
		token->type = DoubleQuote;
	}
	if (!token->value)
		return (0);
	(*i)++;
	return (1);
}

void	tokenize_redir(t_token *token, char *prompt, int *i)
{
	if (prompt[*i] == '<')
	{
		if (prompt[*i + 1] && prompt[*i + 1] == '<')
		{
			token->type = RedirDelim;
			(*i)++;
		}
		else
			token->type = RedirInput;
	}
	else if (prompt[*i] == '>')
	{
		if (prompt[*i + 1] && prompt[*i + 1] == '>')
		{
			token->type = RedirAppend;
			(*i)++;
		}
		else
			token->type = RedirOutput;
	}
	(*i)++;
}

int	tokenize_env(t_token *token, char *prompt, int *i, int is_variable)
{
	token->type = EnvVariable;
	(*i)++;
	token->value = scan_word(prompt, i, is_variable);
	if (!token->value)
		return (0);
	return (1);
}

int	tokenize_word(t_token *token, char *prompt, int *i, int is_variable)
{
	token->type = Word;
	token->value = scan_word(prompt, i, is_variable);
	if (!token->value)
		return (0);
	return (1);
}

void	tokenize_one(t_token *token, int *i, t_token_type type)
{
	token->type = type;
	(*i)++;
}
