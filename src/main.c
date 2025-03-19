/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/02/11 16:03:52 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/26 14:59:34 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_status_codes.h"
#include "list.h"
#include "token.h"
#include "tokenizer.h"
#include "pipeline.h"
#include "pipeline_builder.h"
#include "pipeline_runner.h"
#include "parser.h"
#include "environment.h"
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

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

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	char	**prompt;
	t_list	*tokens;
	t_pipeline **pipeline;
	t_list		*env;

	(void) argc;
	(void)argv;
	line = readline("$> ");
	prompt = (char **)malloc(sizeof(char *));
	if (!prompt)
		return (0);
	pipeline = (t_pipeline **)malloc(sizeof(t_pipeline *));
	if (!pipeline)
		return (free(prompt), 0);
	env = init_environment(envp);
	if (!env)
		return (free(prompt), free(pipeline), 0);
	*pipeline = NULL;
	while (line)
	{
		if (*line)
		{
			*prompt = line;
			tokens = create_token_list(prompt);
			if (!tokens)
			{
				free(line);
				break;
			}
			parse_tokens(tokens, pipeline, env);
			if (*pipeline)
			{	if (run_a_pipeline(*pipeline) == FAILURE)
					printf("Error running pipeline\n");
			}
			add_history(line);
			clear_list(tokens, free);
		}
		free(line);
		line = readline("$> ");
	}
	free(prompt);
	free(pipeline);
	destroy_environment(&env);
	return (0);
}
