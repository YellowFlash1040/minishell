#include "helpers.h"
#include "token.h"
#include "tokenizer.h"
#include "global_status_codes.h"
#include "ft_string.h"
#include "list.h"

int	add_token(t_list *tokens, t_token_type type, char *value, char seperator)
{
	t_token *token;

	token = init_token();
	token->type = type;
	token->value = ft_strdup(value);
	token->seperator = seperator;
	if (!add_to_list(tokens, (void *) token))
		return (free_token(token), false);
	return (true);
}

int	test_tokenizer(char	*prompt, t_list *correct_tokens)
{
	t_list *cur_tokens;
	t_list_node *cur_node;
	t_list_node *correct_node;
	t_token		*cur_tok;
	t_token		*correct_tok;


	cur_tokens = create_token_list(prompt, 0);
	if (!cur_tokens)
		return (FAILURE);
	if (cur_tokens->count != correct_tokens->count)
		return (printf("cur_tokens->count=%d correct_tokens->count=%d\n", cur_tokens->count, correct_tokens->count), destroy_list(&cur_tokens, free_token), FAILURE);
	cur_node = cur_tokens->head;
	correct_node = correct_tokens->head;
	while (correct_node)
	{
		correct_tok = (t_token *) correct_node->value;
		if (!cur_node)
			return (printf("cur_node is NULL\n"), destroy_list(&cur_tokens, free_token), FAILURE);
		cur_tok = (t_token *)cur_node->value;
		if (cur_tok->type != correct_tok->type)
			return (printf("cur_tok->type=%d correct_tok->type=%d\n", cur_tok->type, correct_tok->type), destroy_list(&cur_tokens, free_token), FAILURE);
		if (correct_tok->value && !ft_strcmp(cur_tok->value, correct_tok->value))
			return (printf("cur_tok->value=\"%s\" correct_tok->value=\"%s\"\n", cur_tok->value, correct_tok->value), destroy_list(&cur_tokens, free_token), FAILURE);
		if (correct_tok->seperator && cur_tok->seperator != correct_tok->seperator)
			return (printf("cur_tok->seperator='%c' correct_tok->seperator='%c'\n", cur_tok->seperator, correct_tok->seperator), destroy_list(&cur_tokens, free_token), FAILURE);
		cur_node = cur_node->next;
		correct_node = correct_node->next;
	}
	destroy_list(&cur_tokens, free_token);
	return (SUCCESS);
}

int	test1(void)
{
	char			*prompt = "test<< a.txt<     >$test";
	t_list			*correct_tokens;
	int				result;

	correct_tokens = init_list();
	if (!add_token(correct_tokens, Word, "test", '<'))
		return (FAILURE);
	if (!add_token(correct_tokens, RedirDelim, NULL, ' '))
		return (FAILURE);
	if (!add_token(correct_tokens, Word, "a.txt", '<'))
		return (FAILURE);
	if (!add_token(correct_tokens, RedirInput, NULL, ' '))
		return (FAILURE);
	if (!add_token(correct_tokens, RedirOutput, NULL, '$'))
		return (FAILURE);
	if (!add_token(correct_tokens, EnvVariable, "test", '\0'))
		return (FAILURE);
	if (!add_token(correct_tokens, EndOfInput, NULL, '\0'))
		return (FAILURE);
	result = test_tokenizer(prompt, correct_tokens);
	destroy_list(&correct_tokens, free_token);
	return (result);
}


/*

	TOKENIZE VARIABLES

*/

int	test2(void)
{
	char			*prompt = "var=\"sdsd\"$something";
	t_list			*correct_tokens;
	int				result;

	correct_tokens = init_list();
	if (!add_token(correct_tokens, Word, "var", '='))
		return (FAILURE);
	if (!add_token(correct_tokens, EqualSign, NULL, '"'))
		return (FAILURE);
	if (!add_token(correct_tokens, DoubleQuote, "sdsd", '$'))
		return (FAILURE);
	if (!add_token(correct_tokens, EnvVariable, "something", '\0'))
		return (FAILURE);
	if (!add_token(correct_tokens, EndOfInput, NULL, '\0'))
		return (FAILURE);
	result = test_tokenizer(prompt, correct_tokens);
	destroy_list(&correct_tokens, free_token);
	return (result);
}

int	main(void)
{
	run_a_test(test1, 1, false);
	run_a_test(test2, 2, false);
}
