/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 14:25:15 by ismo          #+#    #+#                 */
/*   Updated: 2025/03/11 14:50:38 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "ft_string.h"
#include "global_status_codes.h"
#include <stdlib.h>

int	get_wlen(char **prompt)
{
	int wlen = 0;

	while ((*prompt)[wlen] && !ft_strchr(OPERATORS, (*prompt)[wlen]) && !is_whitespace((*prompt)[wlen]))
		wlen++;
	return (wlen);
}

char	*scan_word(char **prompt)
{
	int		i;
	int		wlen;
	char	*word;

	i = 0;
	wlen = get_wlen(prompt);
	if (wlen <= 0)
		return (NULL);
	word = (char *)malloc(wlen + 1);
	if (!word)
		return (NULL);
	while (i < wlen)
	{
		word[i] = **prompt;
		i++;
		(*prompt)++;
	}
	word[i] = '\0';
	return (word);
}

void	tokenize_quote(t_token *token, char **prompt)
{
	if (**prompt == '\'')
		token->type = SingleQuote;
	else if (**prompt == '"')
		token->type = DoubleQuote;
	(*prompt)++;
}

void	tokenize_redir(t_token *token, char **prompt)
{
	if (**prompt == '<')
	{
		if ((*prompt)[1] && (*prompt)[1] == '<')
		{
			token->type = RedirDelim;
			(*prompt)++;
		}
		else
			token->type = RedirInput;
	}
	else if (**prompt == '>')
	{
		if ((*prompt)[1] && (*prompt)[1] == '>')
		{
			token->type = RedirAppend;
			(*prompt)++;
		}
		else
			token->type = RedirOutput;
	}
	(*prompt)++;
}

void	tokenize_pipe(t_token *token, char **prompt)
{
	token->type = Pipe;
	(*prompt)++;
}

void	tokenize_env(t_token *token, char **prompt)
{
	token->type = EnvVariable;
	(*prompt)++;
	token->value = scan_word(prompt);
}

void	tokenize_word(t_token *token, char **prompt)
{
	token->type = Word;
	token->value = scan_word(prompt);
}

t_token	*get_next_token(char **prompt)
{
	t_token	*token;

	token = init_token();
	if (!token)
		return (NULL);
	while (**prompt && is_whitespace(**prompt))
		(*prompt)++;
	if (**prompt && ft_strchr("\"\'", **prompt))
		tokenize_quote(token, prompt);
	else if (**prompt && ft_strchr("<>", **prompt))
		tokenize_redir(token, prompt);
	else if (**prompt == '|')
		tokenize_pipe(token, prompt);
	else if (**prompt == '$')
		tokenize_env(token, prompt);
	else if (**prompt && !is_whitespace(**prompt))
		tokenize_word(token, prompt);
	else
		return (NULL);
	return (token);
}
