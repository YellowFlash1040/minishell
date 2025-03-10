#include "helpers.h"
#include "token.h"
#include "tokenizer.h"

t_list	*create_token_list(char **prompt)
{
	t_list *tokens;
	t_token *token;

	tokens = init_list();
	if (!tokens)
		return (NULL);
	token = get_next_token(prompt);
	while (token)
	{
		add_to_list(tokens, get_next_token(prompt));
		token = get_next_token(prompt);
	}
	return (tokens);
}

int	test1()
{
	char			*prompt = "test<< a.txt";
	t_token_type	correct[3] = {Word, RedirDelim, Word};
	t_list			*tokens;
	int				i;

	tokens = create_token_list(&prompt);
	i = 0;
	while (i < 3)
	{
		if (((t_token *) get_node(i, tokens)->value)->type != correct[i])
			return (FAILURE);
	}
	return (SUCCESS);
}

int	main(void)
{
	run_a_test(test1, 0);
}
