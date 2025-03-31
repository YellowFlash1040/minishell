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
#include "expander.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int		g_received_signal = -1;

void	signal_handler(int signum)
{
	if (RL_ISSTATE(RL_STATE_READCMD) && signum == SIGINT)
	{
		write(1, "^C\n", 3);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_received_signal = signum;
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	t_list	*tokens;
	t_pipeline **pipeline;
	t_list		*env;

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	(void) argc;
	(void) argv;
	rl_catch_signals = 0;
	rl_event_hook = NULL;
	pipeline = (t_pipeline **)malloc(sizeof(t_pipeline *));
	*pipeline = NULL;
	if (!pipeline)
		return (0);
	env = init_environment(envp);
	if (!env)
		return (free(pipeline), 0);
	line = readline("$> ");
	while (line)
	{
		if (*line)
		{
			tokens = create_token_list(line);
			if (!tokens)
			{
				free(line);
				break;
			}
			parse_tokens(tokens, pipeline, env);
			destroy_list(&tokens, free_token);
			tokens = NULL;
			if (*pipeline)
			{
				expand_commands(&(*pipeline)->commands);
				g_received_signal = -1;
				run_a_pipeline(*pipeline);
				if (g_received_signal != -1)
				{
					printf("\n");
					rl_on_new_line();
				}
				destroy_pipeline(pipeline);
			}
			add_history(line);
		}
		free(line);
		line = readline("$> ");
	}
	free(pipeline);
	destroy_environment(&env);
	return (0);
}

