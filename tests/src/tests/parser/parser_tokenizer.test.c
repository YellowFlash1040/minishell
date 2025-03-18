#include "helpers.h"
#include "token.h"
#include "tokenizer.h"
#include "global_status_codes.h"
#include "ft_string.h"

t_list	*create_token_list(char **prompt)
{
	t_list *tokens;
	t_token *token;

	token = get_next_token(prompt);
	if (!token)
		return (NULL);
	tokens = init_list();
	if (!tokens)
		return (NULL);
	while (token && token->type != EndOfInput)
	{
		add_to_list(tokens, token);
		token = get_next_token(prompt);
	}
	if (!token)
	{
		clear_list(tokens, free);
		return (NULL);
	}
	add_to_list(tokens, token);
	return (tokens);
}

int	test1(void)
{
	char			*prompt = "test<< a.txt<     >$test";
	t_token_type	correct[] = {Word, RedirDelim, Word, RedirInput, RedirOutput, EnvVariable};
	t_list			*tokens;
	t_token			*token;
	int				i;

	tokens = create_token_list(&prompt);
	if (!tokens)
		return (SUCCESS);
	i = 0;
	while (i < (int) (sizeof(correct) / sizeof(correct[0])))
	{
		token = get_node(i, tokens)->value;
		if (token->type != correct[i])
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	test2(void)
{
	char			*prompt = "";

	if (get_next_token(&prompt)->type == EndOfInput)
		return (SUCCESS);
	return (FAILURE);
}

int	test3(void)
{
	char			*prompt = "\"aa\"$test|             example_word,,,,..,.,.#";
	t_token_type	correct[] = {DoubleQuote, EnvVariable, Pipe, Word, EndOfInput};
	t_list			*tokens;
	t_token			*token;
	int				i;

	tokens = create_token_list(&prompt);
	if (!tokens)
		return (FAILURE);
	if (tokens->count != (sizeof(correct) / sizeof(correct[0])))
		return (FAILURE);
	i = 0;
	while (i < (int) (sizeof(correct) / sizeof(correct[0])))
	{
		token = get_node(i, tokens)->value;
		if (token->type != correct[i])
			return (FAILURE);
		i++;
	}
	token = get_node(0, tokens)->value;
	if (!ft_strcmp(token->value, "aa"))
		return (FAILURE);
	token = get_node(1, tokens)->value;
	if (!ft_strcmp(token->value, "test"))
		return (FAILURE);
	token = get_node(3, tokens)->value;
	if (!ft_strcmp(token->value, "example_word,,,,..,.,.#"))
	{
		printf("%s\n", token->value);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	main(void)
{
	run_a_test(test1, 1, false);
	test3();
	run_a_test(test3, 3, false);
}
