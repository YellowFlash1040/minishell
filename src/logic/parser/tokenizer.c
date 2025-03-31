/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ismo <ismo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 14:25:15 by ismo          #+#    #+#                 */
/*   Updated: 2025/04/01 00:17:02 by ismo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "token.h"
#include "ft_string.h"
#include "global_status_codes.h"
#include <stdlib.h>

int	get_wlen(char *prompt, int *i, int is_variable)
{
	int wlen = 0;
	char *operators;

	if (!is_variable)
		operators = OPERATORS;
	else
		operators = OPERATORS_VAR;
	while (prompt[*i + wlen] && !ft_strchr(operators, prompt[*i + wlen]) && !is_whitespace(prompt[*i + wlen]))
		wlen++;
	return (wlen);
}

char	*scan_word(char *prompt, int *i, int is_variable)
{
	int		j;
	int		wlen;
	char	*word;

	j = 0;
	wlen = get_wlen(prompt, i, is_variable);
	word = (char *)malloc(wlen + 1);
	if (!word)
		return (NULL);
	while (j < wlen)
	{
		word[j] = prompt[*i];
		j++;
		(*i)++;
	}
	word[j] = '\0';
	return (word);
}

char	*read_quote(char quote, char *prompt, int *i)
{
	int		j;
	char 	*value;

	j = 0;
	while (prompt[*i + j + 1] && prompt[*i + j + 1] != quote)
		j++;
	if (!prompt[*i + j + 1])
		return (NULL);
	value = (char *) malloc(j + 1);
	if (!value)
		return (NULL);
	j = 0;
	(*i)++;
	while (prompt[*i] != quote)
	{
		value[j++] = prompt[*i];
		(*i)++;
	}
	value[j] = '\0';
	return (value);
}

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
		return (FAILURE);
	(*i)++;
	return (SUCCESS);
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

void	tokenize_pipe(t_token *token, int *i)
{
	token->type = Pipe;
	(*i)++;
}

void	tokenize_eq(t_token *token, int *i)
{
	token->type = EqualSign;
	(*i)++;
}

int	tokenize_env(t_token *token, char *prompt, int *i, int is_variable)
{
	token->type = EnvVariable;
	(*i)++;
	token->value = scan_word(prompt, i, is_variable);
	if (!token->value)
		return (FAILURE);
	return (SUCCESS);
}

int	tokenize_word(t_token *token, char *prompt, int *i, int is_variable)
{
	token->type = Word;
	token->value = scan_word(prompt, i, is_variable);
	if (!token->value)
		return (FAILURE);
	return (SUCCESS);
}

t_token	*get_next_token(char *prompt, int *i, int is_variable)
{
	t_token	*token;

	token = init_token();
	if (!token)
		return (NULL);
	while (prompt[*i] && is_whitespace(prompt[*i]))
		(*i)++;
	if (prompt[*i] && ft_strchr("\"\'", prompt[*i]))
	{
		if (tokenize_quote(token, prompt, i) == FAILURE)
			return (free(token), NULL);
	}
	else if (prompt[*i] && ft_strchr("<>", prompt[*i]))
		tokenize_redir(token, prompt, i);
	else if (prompt[*i] == '|')
		tokenize_pipe(token, i);
	else if (is_variable && prompt[*i] == '=')
		tokenize_eq(token, i);
	else if (prompt[*i] == '$')
	{
		if (tokenize_env(token, prompt, i, is_variable) == FAILURE)
			return (free(token), NULL);
	}
	else if (prompt[*i] && !is_whitespace(prompt[*i]))
	{
		if (tokenize_word(token, prompt, i, is_variable) == FAILURE)
			return (free(token), NULL);
	}
	else
		token->type = EndOfInput;
	if (token->type != EndOfInput)
		token->seperator = prompt[*i];
	return (token);
}

t_list	*create_token_list(char *prompt, int is_variable)
{
	t_list *tokens;
	t_token *token;
	int		i;

	i = 0;
	token = get_next_token(prompt, &i, is_variable);
	if (!token)
		return (NULL);
	tokens = init_list();
	if (!tokens)
		return (NULL);
	while (token && token->type != EndOfInput)
	{
		add_to_list(tokens, token);
		token = get_next_token(prompt, &i, is_variable);
	}
	if (!token)
	{
		destroy_list(&tokens, free_token);
		return (NULL);
	}
	add_to_list(tokens, token);
	return (tokens);
}
