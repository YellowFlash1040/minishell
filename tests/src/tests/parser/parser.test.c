#include "helpers.h"
#include "token.h"
#include "tokenizer.h"
#include "parser.h"
#include "global_status_codes.h"
#include "ft_string.h"
#include "class_printer.h"
#include "pipeline_runner.h"

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
	return (tokens);
}

int test1(void)
{
	char	*prompt;
	t_list *tokens;
	t_pipeline **pipeline;

	pipeline = malloc(sizeof(t_pipeline **));
	if (!pipeline)
		return (FAILURE);
	prompt = "ls > a.txt | echo 1";
	tokens = create_token_list(&prompt);
	if (!tokens)
		return (FAILURE);
	if (parse_tokens(tokens, pipeline) == FAILURE)
		return (FAILURE);
	if (!(*pipeline))
		return (FAILURE);
	run_a_pipeline(*pipeline);
	return (SUCCESS);
}

int main(void)
{
	run_a_test(test1, 1, false);
}
