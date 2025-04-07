#include "helpers.h"
#include "token.h"
#include "tokenizer.h"
#include "variable.h"
#include "parser.h"
#include "parser_utils.h"
#include "global_status_codes.h"
#include "ft_string.h"
#include "class_printer.h"
#include "pipeline_runner.h"

t_list* environment;

/* test n_args */
int test1(void)
{
	char	*prompt;
	t_list *tokens;
	
	prompt = ft_strdup("a \"aa\" b");
	tokens = create_token_list(prompt, 0);
	free(prompt);
	if (!tokens)
		return (FAILURE);
	printf("type: \"%d\"\n", read_token(tokens, 0)->type);
	printf("value: \"%s\"\n", read_token(tokens, 0)->value);
	printf("seperator: \"%c\"\n",  read_token(tokens, 0)->seperator);
	printf("n_args: %d\n", n_args(tokens, 0));
	if (n_args(tokens, 0) != 3)
		return (FAILURE);
	destroy_list(&tokens, free_token);
	return (SUCCESS);
}

/* test quote_string */
int test2(void)
{
	char	*quoted_str;
	t_token *token;

	token = init_token();
	if (!token)
		return (FAILURE);
	token->type = DoubleQuote;
	token->value = ft_strdup("test");
	quoted_str = quote_str(token);
	printf("%s\n ", quoted_str);
	if (!quoted_str || !ft_strcmp(quoted_str, "\"test\""))
		return (FAILURE);
	free(quoted_str);
	free_token(token);
	return (SUCCESS);
}

int main(int argc, t_string args[], t_string envp[])
{
	(void)argc;
	(void)args;

	environment = init_environment(envp);

	int (*tests[])(void) =
		{
			test1,
			test2
		};

	for (int i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++)
		run_a_test(tests[i], i + 1, false);

	// test1();

	destroy_environment(&environment);
}
