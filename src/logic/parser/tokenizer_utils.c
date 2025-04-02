/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenne <ibenne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:15:24 by ismo              #+#    #+#             */
/*   Updated: 2025/04/02 14:07:47 by ibenne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "stdlib.h"
#include "ft_string.h"

int	get_wlen(char *prompt, int *i, char *delims)
{
	int		wlen;

	wlen = 0;
	while (prompt[*i + wlen]
		&& index_of(prompt[*i + wlen], delims) == -1
		&& !is_whitespace(prompt[*i + wlen]))
		wlen++;
	return (wlen);
}

char	*scan_word(char *prompt, int *i, char *delims)
{
	int		j;
	int		wlen;
	char	*word;

	j = 0;
	wlen = get_wlen(prompt, i, delims);
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
	char	*value;

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
